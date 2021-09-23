#pragma once

#include "base_timer.h"

class execution_time 
    : public base_timer {
public:
    execution_time() {
        start();
    }

    ~execution_time() {
        stop();
        printf("execution time : %lld ms\n", ms());
    }
};