#pragma once
#include "SingletonBehaviour.h"

class SceneManager : public SingletonBehaviour<SceneManager>
{
	DECLARE_SINGLE(SceneManager);

public:
	virtual ~SceneManager() override = default;

public:
	// TODO : ���Ŀ� �� Ŭ���� ���� �� �ۼ�.
	
private:

};

