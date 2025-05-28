// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#ifndef SBG_ECOM_ANALYSER_CORE_SESSION_INFO_H
#define SBG_ECOM_ANALYSER_CORE_SESSION_INFO_H

// STL headers
#include <string>

namespace sbg
{
	class CSessionInfo
	{
	public:
		//
		// Parameters
		//
		std::string getVersion() const;

		//
		// Operations
		//
		static CSessionInfo fromJson(const std::string &jsonStr);

	private:
		std::string m_version;
	};

}// namespace sbg

#endif// SBG_ECOM_ANALYSER_CORE_SESSION_INFO_H
