#pragma once
#include "SingletonBehaviour.h"

class ResourceManager : public SingletonBehaviour<ResourceManager>
{
	DECLARE_SINGLE(ResourceManager);

public:
	virtual ~ResourceManager() override = default;

public:
	// TODO : 이후에 컴포넌트를 만들 때 작성.

private:

};

