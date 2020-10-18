/*
*	Juno precompiled Header
*/

#pragma once

#include "Juno/Core/PlatformDetection.h"

#ifdef JUNO_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif
#endif


#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

#include "Juno/Core/Core.h"
#include "Juno/Core/Log.h"

#include "Juno/Debug/Instrumentor.h"

#ifdef JUNO_PLATFORM_WINDOWS
	#include <Windows.h>
#endif