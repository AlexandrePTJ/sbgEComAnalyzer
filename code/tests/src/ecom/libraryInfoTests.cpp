// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#include <ecom/libraryInfo.h>

// Catch2 headers
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Get sbgECom version", "[core]")
{
	REQUIRE(sbg::CSbgEComLibraryInfo::getVersion() == "5.2.590-stable");
}
