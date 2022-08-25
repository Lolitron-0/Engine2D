#include "Line.hpp"
#include <Window.hpp>



Line::Line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
	: PrimitiveShape(Colors::white,2)
{
	mGlVertices = { Window::getInstance().screenToGlX(x1), 
		Window::getInstance().screenToGlY(y1),
		Window::getInstance().screenToGlX(x2), 
		Window::getInstance().screenToGlY(y2) 
	};
}

Line::Line(Vector2<GLfloat> start, Vector2<GLfloat> end)
	:Line(start.x,start.y,end.x,end.y)
{

}

