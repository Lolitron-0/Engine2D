#ifndef UIOBEJCT_HPP
#define UIOBEJCT_HPP
#include <vector>
#include "../Utils/Event.hpp"

namespace ui
{

    class UiObject
    {
    public:
        virtual bool processEvent(const Event&) {return false;};

        //when an object recieves an Event it first processes it itself
        //and then for all children. If child processed it sucsessfully
        //processing will stop (da ya sam pridumal)
        bool pushEvent(const Event& event)
        {
            if(processEvent(event)) return true; //маску сначала на себя потом на ребенка
            for(int i=0;i<mChildren.size();i++)
            {
                if(mChildren[i]->pushEvent(event))
                    return true;
            }
            return false;
        }
        virtual void draw()=0;

    protected:
       std::vector<std::shared_ptr<UiObject>> mChildren;
    };

}

#endif // UIOBEJCT_HPP
