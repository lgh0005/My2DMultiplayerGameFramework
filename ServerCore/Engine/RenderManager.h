#pragma once
#include "SingletonBehaviour.h"

class RenderManager : public SingletonBehaviour<RenderManager>
{
	DECLARE_SINGLE(RenderManager);

public:
	virtual ~RenderManager() override = default;

public:
	virtual void Init() override;
	virtual void Update() override;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

private:

};

