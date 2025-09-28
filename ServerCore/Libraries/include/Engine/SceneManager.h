#pragma once
#include "SingletonBehaviour.h"

class SceneManager : public SingletonBehaviour<SceneManager>
{
	DECLARE_SINGLE(SceneManager);

public:
	virtual ~SceneManager() override = default;

public:
	// TODO : 이후에 씬 클래스 제작 후 작성.
	
private:

};

