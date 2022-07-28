#pragma once
#include <vector>
#include <functional>

template <typename...Args>
class CallbackDelegate
{
private:
	typedef std::function<void(Args...)> Callback;
	typedef std::vector<Callback> CallbackQueue;
	typedef typename CallbackQueue::const_iterator Iterator;

public:
	CallbackDelegate() = default;

	void pushCallback(const Callback& f)
	{
		this->mCallbackQueue.push_back(f);
	}

	void callAll(Args... args)
	{
		for (Callback c : this->mCallbackQueue)
			c(args...);
	}

private:

	CallbackQueue mCallbackQueue;
};

