// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2025 SBG Systems and Contributors

#include "libraryInfo.h"

// sbgECom headers
#include <sbgEComGetVersion.h>

namespace sbg
{
	//
	// Parameters
	//
	std::string CSbgEComLibraryInfo::getVersion()
	{
		return sbgEComGetVersionAsString();
	}

}// namespace sbg
