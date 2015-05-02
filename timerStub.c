#include "timerStub.h"

void Timer_Create(Timer timer)
{
  Timer_SetTime(timer, 0);
}
long Timer_GetTime(Timer timer)
{
  return timer->time;
}
void Timer_SetTime(Timer timer, long time)
{
  timer->time = time;
}
