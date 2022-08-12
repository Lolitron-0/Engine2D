#pragma once
#include <GameObject.hpp>

struct KeyEventArgs
{
public:
	int key;
	int mods;
};

class KeyListener
{
public:
	KeyListener();

	//TODO: non-GLFW keys
	virtual void onKeyDown(const KeyEventArgs& args)=0;
	virtual void onKeyUp(const KeyEventArgs& args)=0;
private:

};
