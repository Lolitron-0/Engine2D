#include "UiWindow.hpp"

UiWindow::UiWindow(int w,int h)
	:mShape(0,0,w,h)
{

}

void UiWindow::draw()
{
	mShape.draw();
}
