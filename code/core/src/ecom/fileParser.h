// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#ifndef SBG_ECOM_ANALYSER_CORE_FILE_PARSER_H
#define SBG_ECOM_ANALYSER_CORE_FILE_PARSER_H

// STL headers
#include <filesystem>
#include <memory>

namespace sbg
{
	class CFileParserPrivate;
	class CFileParser
	{
	public:
		CFileParser();
		virtual ~CFileParser();

		//
		// Operations
		//
		void process(const std::filesystem::path &path);

	private:
		std::unique_ptr<CFileParserPrivate> m_pImpl;
	};

}// namespace sbg

#endif// SBG_ECOM_ANALYSER_CORE_FILE_PARSER_H
