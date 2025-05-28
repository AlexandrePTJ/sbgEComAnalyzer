// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#include <ecom/fileParser.h>

// Catch2 headers
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Read sbgECom Data", "[core]")
{
	auto data1Path = std::filesystem::path(SBG_TEST_DATA_DIR) / "data_2.bin";
	sbg::CFileParser parser;
	REQUIRE_NOTHROW(parser.process(data1Path));
}
