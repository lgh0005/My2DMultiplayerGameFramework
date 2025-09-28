#pragma once
#include "SingletonBehaviour.h"

enum class InputState
{
	None,
	Press,
	Down,
	Up,
	END
};

class InputManager : public SingletonBehaviour<InputManager>
{
	DECLARE_SINGLE(InputManager);

public:
	virtual ~InputManager() override = default;

public:
	virtual void Update() override;

public:
	void GetEvent(const SDL_Event& e);

	// Input : Keyboard
	bool GetKey(Inputs::Key key) { return InputState::Press == GetKeyState(key); }
	bool GetKeyDown(Inputs::Key key) { return InputState::Down == GetKeyState(key); }
	bool GetKeyUp(Inputs::Key key) { return InputState::Up == GetKeyState(key); }
	bool GetKeymodDown(Inputs::Keymod keymod) { return (SDL_GetModState() & static_cast<SDL_Keymod>(keymod)) != 0; }

	// Input : Mouse
	bool MouseHold(Inputs::Mouse button) { return InputState::Press == GetMouseState(button); }
	bool MouseClick(Inputs::Mouse button) { return InputState::Down == GetMouseState(button); }
	bool MouseUp(Inputs::Mouse button) { return InputState::Up == GetMouseState(button); }

private:
	InputState GetKeyState(Inputs::Key key) { return _keyboardState[static_cast<uint16>(key)]; }
	InputState GetMouseState(Inputs::Mouse mouse) { return _mouseState[static_cast<uint8>(mouse)]; }

private:
	array<InputState, SDL_NUM_SCANCODES> _keyboardState{};
	SDL_Keymod _keymodState = KMOD_NONE;

	array<InputState, Inputs::MOUSE_COUNT> _mouseState{};
};

