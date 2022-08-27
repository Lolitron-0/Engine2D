#include "UiWindow.hpp"

namespace ui
{

    UiWindow::UiWindow(int w,int h)
        :mBorder(0,0,w,h,"Resources/border.png")
    {
    }

    bool UiWindow::processEvent(const Event& event)
    {
        switch (event.type) {
        case Event::EventType::MouseDown:
            if(mBorder.getRect().contains(event.mouseButton.getPositionVector()))
            {
                mGrabbed = true;
                mGrabOffset = event.mouseButton.getPositionVector() - mBorder.getRect().getTopLeft();
                return true;
            }
            break;
        case Event::EventType::MouseMove:
            if(mGrabbed)
                mBorder.setPosition(event.mouseMove.getPositionVector()-mGrabOffset);
            return true;
            break;
        case Event::EventType::MouseUp:
            mGrabbed = false;
            break;
        default:
            break;
        }
        return false;
    }


    void UiWindow::draw()
    {
        mBorder.draw();
    }

}
