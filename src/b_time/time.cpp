//
// Created by brett on 2021-01-18.
//
#include "time.h"
#include <chrono>

long long delta = 0;

void setDelta(long long d) {
    delta = d;
}

long long getDelta(){
    return delta;
}

double getDeltaMS(){
    return ((double) delta)/((double)1000000);
}

long long getNanoTime(){
    long long nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    return nanoseconds;
}

