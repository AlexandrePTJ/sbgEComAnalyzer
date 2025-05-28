// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#ifndef SBG_ECOM_ANALYSER_CORE_FILE_PARSER_P_H
#define SBG_ECOM_ANALYSER_CORE_FILE_PARSER_P_H

// STL headers
#include <filesystem>

// sbgECom headers
#include <sbgECom.h>
#include <sessionInfo/sbgEComSessionInfo.h>

namespace sbg
{
	class CFileParserPrivate
	{
	public:
		CFileParserPrivate() = default;
		virtual ~CFileParserPrivate();

		//
		// Operations
		//
		void initialize(const std::filesystem::path &path);
		void processAll();
		void handleSessionInformation(const SbgEComLogSessionInfo &data);

		//
		// Data
		//
		SbgInterface          m_interface;
		SbgEComHandle         m_parserHandle;
		SbgEComSessionInfoCtx m_ecomSessionInfoCtx;
	};

}// namespace sbg

#endif// SBG_ECOM_ANALYSER_CORE_FILE_PARSER_P_H
