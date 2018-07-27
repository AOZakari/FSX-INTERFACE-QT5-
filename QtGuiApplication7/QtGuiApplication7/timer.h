#ifndef TIMER_H
#define TIMER_H
#ifndef _TIMER_
#define _TIMER_

#include <ctime>
#include <time.h>

class Timer {
    clock_t counter;
public:
    Timer():counter(0) {};

    bool elasped(clock_t ms)
    {
        clock_t tick = clock();

        if(tick - counter >= ms)
        {
             counter = tick;
             return true;
        }

        return false;
    }
};
#endif
#endif // TIMER_H
