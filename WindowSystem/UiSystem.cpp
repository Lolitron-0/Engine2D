#include "UiSystem.hpp"
#include "UiWindow.hpp"

namespace ui {

UiSystem::UiSystem(Window& w)
    :EventListener(w)
{

}

void UiSystem::createWindow(const Vector2<int> &position, const Vector2<int> &size)
{
    mChildren.push_back(std::shared_ptr<UiWindow>(new UiWindow(size.x, size.y)));
}

void UiSystem::draw()
{
    for(int i=0;i<mChildren.size();i++)
        mChildren[i]->draw();
}

void UiSystem::handle(const Event & event)
{
    pushEvent(event); //start feeding forward
}

} // namespace ui
