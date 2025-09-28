#pragma once

// C++
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <concepts>
#include <type_traits>
#include <fstream>
#include <sstream>
#include <format>
using namespace std;

// SDL
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h> 
#pragma comment(lib, "SDL/SDL2.lib")
#pragma comment(lib, "SDL/SDL2main.lib")
#pragma comment(lib, "SDL/SDL2_image.lib")
#pragma comment(lib, "SDL/SDL2_ttf.lib")
#pragma comment(lib, "SDL/SDL2_mixer.lib")

// Misc
#include "Types.h"
#include "Defines.h"
#include "Values.h"
#include "Enums.h"

// Managers
#include "TimeManager.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "ResourceManager.h"

#define TIME TimeManager::GetInstance()
#define RENDER RenderManager::GetInstance()
#define INPUT InputManager::GetInstance()
#define RESOURCE ResourceManager::GetInstance()
