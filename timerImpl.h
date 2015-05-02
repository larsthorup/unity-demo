#include "timer.h"

struct TimerStruct
{
  long not_used;
};

typedef void (* Timer_AlarmProc)();

void Timer_SetIntervalAlarm(Timer timer, long ms, Timer_AlarmProc);
