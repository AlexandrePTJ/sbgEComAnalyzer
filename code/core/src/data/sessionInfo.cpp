// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#include "sessionInfo.h"

// nlohmann_json headers
#include <nlohmann/json.hpp>

namespace sbg
{
	//
	// Parameters
	//
	std::string CSessionInfo::getVersion() const
	{
		return m_version;
	}

	//
	// Operations
	//
	CSessionInfo CSessionInfo::fromJson(const std::string &jsonStr)
	{
		auto json = nlohmann::json::parse(jsonStr);

		CSessionInfo sessionInfo;
		sessionInfo.m_version = json["version"];

		return sessionInfo;
	}

}// namespace sbg
