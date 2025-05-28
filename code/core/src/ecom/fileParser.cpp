// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#include "fileParser.h"
#include "fileParser_p.h"

// fmt headers
#include <fmt/format.h>

// sbgECom headers
#include <interfaces/sbgInterfaceFile.h>

namespace sbg
{
	//
	// Static operations
	//
	static SbgErrorCode onNewDataReceived(SbgEComHandle * /*pHandle*/, SbgEComClass msgClass, SbgEComMsgId msg, const SbgEComLogUnion *pLogData, void *pUserArg)
	{
		SbgErrorCode errorCode          = SBG_NO_ERROR;
		auto         pFileParserPrivate = static_cast<CFileParserPrivate *>(pUserArg);

		if (msgClass == SBG_ECOM_CLASS_LOG_ECOM_0)
		{
			switch (msg)
			{
			case SBG_ECOM_LOG_SESSION_INFO:
				pFileParserPrivate->handleSessionInformation(pLogData->sessionInfoData);
				break;

			default:
				break;
			}
		}

		return errorCode;
	}

	//
	// Private implementation
	//
	CFileParserPrivate::~CFileParserPrivate()
	{
		sbgInterfaceDestroy(&m_interface);
	}

	//
	// Private operations
	//
	void CFileParserPrivate::initialize(const std::filesystem::path &path)
	{
		auto errorCode = sbgInterfaceFileOpen(&m_interface, path.string().c_str());
		if (errorCode != SBG_NO_ERROR)
		{
			throw std::runtime_error(fmt::format("Error opening file '{}': {}", path.string(), sbgErrorCodeToString(errorCode)));
		}

		sbgEComInit(&m_parserHandle, &m_interface);

		sbgEComSetReceiveLogCallback(&m_parserHandle, onNewDataReceived, this);
		sbgEComSessionInfoCtxConstruct(&m_ecomSessionInfoCtx);
	}

	void CFileParserPrivate::processAll()
	{
		while (sbgEComHandle(&m_parserHandle) != SBG_NOT_READY) {}

		sbgEComClose(&m_parserHandle);
	}

	void CFileParserPrivate::handleSessionInformation(const SbgEComLogSessionInfo &data)
	{
		auto errorCode = sbgEComSessionInfoCtxProcess(&m_ecomSessionInfoCtx, data.pageIndex, data.nrPages, data.buffer, data.size);
		if (errorCode == SBG_NO_ERROR)
		{
			auto jsonStr = std::string(sbgEComSessionInfoCtxGetString(&m_ecomSessionInfoCtx));
			// TODO
		}
	}

	//
	// Public implementation
	//
	CFileParser::CFileParser():
	m_pImpl(std::make_unique<CFileParserPrivate>())
	{
	}

	CFileParser::~CFileParser() = default;

	//
	// Public operations
	//
	void CFileParser::process(const std::filesystem::path &path)
	{
		m_pImpl->initialize(path);
		m_pImpl->processAll();
	}

}// namespace sbg
