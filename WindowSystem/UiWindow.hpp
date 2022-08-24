#ifndef UI_WINDOW_HPP
#define UI_WINDOW_HPP
#include "../GLTest/RectangleShape.hpp"


enum class MouseActions
{
	MouseDown,
	MouseUp,
	MouseMove
};

class UiWindow 
{
	public:
		UiWindow(int w, int h);

		bool onMouse(int key, MouseActions action, int x, int y);


		void draw();

	private:
		RectangleShape mShape;
};

#endif