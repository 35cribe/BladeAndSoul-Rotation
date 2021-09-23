#pragma once


#include <chrono>

class base_timer {
public:
    void start() {
        elapsed_time = std::chrono::duration<long long>::zero();
        start_time = std::chrono::steady_clock::now();
    }

    void stop() {
        elapsed_time = std::chrono::steady_clock::now() - start_time;
    }

    long long ms() const {
        return (std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time)).count();
    }

private:
	std::chrono::time_point<std::chrono::steady_clock> start_time;
	std::chrono::nanoseconds elapsed_time;
};