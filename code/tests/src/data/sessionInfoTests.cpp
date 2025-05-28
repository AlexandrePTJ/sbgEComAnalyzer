// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#include <data/sessionInfo.h>

// Catch2 headers
#include <catch2/catch_test_macros.hpp>

TEST_CASE("CSessionInfo from JSON", "[core]")
{
	auto jsonStr = R"({"version": "1.1.0.0"})";

	CHECK_NOTHROW(sbg::CSessionInfo::fromJson(jsonStr));

	auto sessionInfo = sbg::CSessionInfo::fromJson(jsonStr);
	REQUIRE(sessionInfo.getVersion() == "1.1.0.0");
}
