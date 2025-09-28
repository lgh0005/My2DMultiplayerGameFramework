#pragma once

// ServerCore
#include "ServerCore/CorePch.h"

// Game Engine Core
#include "Engine/EnginePch.h"
#ifdef _DEBUG
#pragma comment(lib, "Engine/Debug/Engine.lib")
#else
#pragma comment(lib, "Engine/Release/Engine.lib")
#endif

// Misc
#include "Engine/Game.h"