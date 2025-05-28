// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

// STL headers
#include <filesystem>

// CLI11 headers
#include <CLI/CLI.hpp>

// spdlog
#include <spdlog/spdlog.h>

// sbgEComHeaders
#include <sbgCommon.h>

static void onSBGEcomMessageCallback(const char * /*pFileName*/, const char *pFunctionName, uint32_t /*line*/, const char * /*pCategory*/, SbgDebugLogType logType, SbgErrorCode errorCode, const char *pMessage)
{
	switch (logType)
	{
	case SBG_DEBUG_LOG_TYPE_ERROR:
		spdlog::error("sbgECom [{}] {}: {}", sbgErrorCodeToString(errorCode), pFunctionName, pMessage);
		break;
	case SBG_DEBUG_LOG_TYPE_INFO:
		spdlog::info("sbgECom [{}] {}: {}", sbgErrorCodeToString(errorCode), pFunctionName, pMessage);
		break;
	case SBG_DEBUG_LOG_TYPE_DEBUG:
		spdlog::debug("sbgECom [{}] {}: {}", sbgErrorCodeToString(errorCode), pFunctionName, pMessage);
		break;
	default:
		spdlog::warn("sbgECom [{}] {}: {}", sbgErrorCodeToString(errorCode), pFunctionName, pMessage);
		break;
	}
}

int main(int argc, char *argv[])
{
	//
	// Register sbgECom generic error logger to print through spdlog
	//
	sbgCommonLibSetLogCallback(onSBGEcomMessageCallback);

	//
	// Create CLI11 app with options
	//
	CLI::App app("sbgECom Analyzer");

	std::filesystem::path filePath;
	auto                  filePathOption = app.add_option("-f,--file", filePath, "sbgECom log file path")->check(CLI::ExistingFile);

	std::filesystem::path dirPath;
	app.add_option("-d,--dir", dirPath, "sbgECom logs directory")->excludes(filePathOption)->check(CLI::ExistingDirectory);

	CLI11_PARSE(app, argc, argv);

	if (filePath.has_filename())
	{
		// TODO
		spdlog::info("Processing {}.", filePath.string());
	}
	else if (dirPath.has_filename())
	{
		// TODO
		spdlog::info("Processing {}.", dirPath.string());
	}
	else
	{
		spdlog::info("Nothing to do.");
	}

	return 0;
}
