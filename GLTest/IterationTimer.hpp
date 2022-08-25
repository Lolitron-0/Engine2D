#ifndef ITERATION_TIMER_HPP
#define ITERATION_TIMER_HPP
#include "../Utils/Utils.hpp"
#include "../Utils/Clock.hpp"

class IterationTimer : public Singleton<IterationTimer>
{
public:
	IterationTimer(){}

	void reset()
	{
		mClock.restart();
	}

	float getGameSpeedKoeff()
	{
		return mClock.elapsedMs()/5;
	}
private:
	Clock mClock;
};


#endif
