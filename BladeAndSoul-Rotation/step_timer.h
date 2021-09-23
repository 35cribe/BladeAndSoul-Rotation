#pragma once

#include "base_timer.h"

#include <functional>
#include <thread>
class step_timer
	: public base_timer {

public:
	step_timer() noexcept(false) : delta_time(1000) {
		max_delta = 100;
		base_timer::start();
	}

	//template<typename F, typename...Args>
	template <class _Fn, class... _Args, std::enable_if_t<!std::is_same_v<std::_Remove_cvref_t<_Fn>, step_timer>, int> = 0>
	void update(_Fn&& _Fx, _Args&&... _Ax) {

		base_timer::stop();

		long long time_delta = ms();

		if (time_delta > max_delta) {
			time_delta = max_delta;
		}

		accumulator += time_delta;

		while (accumulator >= delta_time) {
			_Fx(_Ax...);
			accumulator -= delta_time;
		}

		base_timer::start();
	}

	void set_framerate(long long fps) {
		delta_time = static_cast<long long>((1.0 / static_cast<float>(fps)) * 1000);
	}

private:
	long long max_delta = 0;
	long long accumulator = 0;
	long long delta_time = 0;
};