#pragma once
#include "SingletonBehaviour.h"

class AudioManager : public SingletonBehaviour<AudioManager>
{
	DECLARE_SINGLE(AudioManager);

public:
	virtual ~AudioManager() override;

public:
	virtual void Init() override;

private:

};

