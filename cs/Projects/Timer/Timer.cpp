#include "Timer.h"

Timer::Timer() { minutes = 0; }

void Timer::setMinutes(int n) { minutes = n; }

int Timer::getMinutes() { return minutes; }

void Timer::reset() { minutes = 0; }