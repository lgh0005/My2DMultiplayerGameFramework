#include "pch.h"
#include "Game.h"

unique_ptr<Game> GAME = make_unique<Game>();

void Game::Init()
{
	// Init Managers
	RENDER.Init();
}

void Game::Launch()
{
    // Event Looping
    while (_running)
    {
        // Update TimeManager
        TIME.Update();

        // Event Polling
        while (SDL_PollEvent(&_event))
        {
            if (_event.type == SDL_QUIT)
                _running = false;

            // Input event polling
            INPUT.GetEvent(_event);
        }

        // Update Logic
        Update();
    }
}

void Game::Update()
{
    INPUT.Update();
    RENDER.Update();
}