#ifndef UI_WINDOW_HPP
#define UI_WINDOW_HPP
#include "../Utils/Sprite.hpp"
#include "UiObject.hpp"

namespace ui
{

    class UiWindow : public UiObject
    {
        public:
            UiWindow(int w, int h);

            bool processEvent(const Event&) override;

            void draw() override;

        private:
            Sprite mBorder;
            bool mGrabbed;
            Vector2<int> mGrabOffset;
    };

}

#endif
