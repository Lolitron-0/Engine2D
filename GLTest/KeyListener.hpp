#pragma once
#include <GameObject.hpp>

HAS_SYSTEM(KeyListenerSystem)

class KeyListener
{
public:
	//TODO: non-GLFW keys
	void onKeyDown(int key, int mods);
private:

};
