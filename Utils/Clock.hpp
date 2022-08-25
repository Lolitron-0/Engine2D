#pragma once
#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <ctime>

class Clock 
{
   public:

        Clock()
        {
            start=clock();
        }

        Clock(double start)
        {
            this->start=start;
        }

        void restart()
        {
            start=clock();
        }

        //return elapsed time in ms
        double elapsedMs()
        {
            return (static_cast<double>(clock() - start) / CLOCKS_PER_SEC) * 1000.;
				}

private:

        double start;
};
#endif
