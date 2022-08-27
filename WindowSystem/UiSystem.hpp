#ifndef UI_UISYSTEM_HPP
#define UI_UISYSTEM_HPP
#include "Window.hpp"
#include "EventListener.hpp"
#include "UiObject.hpp"

namespace ui {

class UiSystem : public UiObject, EventListener
{
public:
    UiSystem(Window&);

    void createWindow(const Vector2<int>& position, const Vector2<int>& size);

    void draw() override;

    void handle(const Event&) override;

};

} // namespace ui

#endif // UI_UISYSTEM_HPP
