#pragma once

enum class ComponentType
{
	None,
	Transform,
	Sprite,
	Script,
	Collider,
	Text
};

class Component : public enable_shared_from_this<Component>
{

};

