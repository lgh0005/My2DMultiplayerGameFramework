#include "pch.h"
#include "RenderManager.h"

void RenderManager::Init()
{
	// Init Window
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow
	(
		WindowConfig::GameTitle,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WindowConfig::GWinSizeX, WindowConfig::GWinSizeY,
		SDL_WINDOW_SHOWN
	);
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	// Init font
	TTF_Init();
}

void RenderManager::Update()
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	SDL_RenderClear(_renderer);

	// TODO : Render Objects

	SDL_RenderPresent(_renderer);
}
