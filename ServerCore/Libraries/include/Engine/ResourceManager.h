#pragma once
#include "SingletonBehaviour.h"

class ResourceManager : public SingletonBehaviour<ResourceManager>
{
	DECLARE_SINGLE(ResourceManager);

public:
	virtual ~ResourceManager() override = default;

public:
	// TODO : ���Ŀ� ������Ʈ�� ���� �� �ۼ�.

private:

};

