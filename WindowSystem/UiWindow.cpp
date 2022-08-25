#include "UiWindow.hpp"

UiWindow::UiWindow(int w,int h)
    :mBorder(0,0,w,h,"Resources/border.png")
{

}

void UiWindow::draw()
{
    mBorder.draw();
}
