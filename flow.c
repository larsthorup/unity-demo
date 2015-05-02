#include "flow.h"

void Flow_Create(Flow flow, Counter counter, Timer timer, long pulseCountPerFlowUnit)
{
  flow->timer = timer;
  flow->counter = counter;
  flow->startTime = Timer_GetTime(timer);
  Counter_Exchange(counter, 0); // Note: ignores previous value of counter
  flow->pulseCountPerFlowUnit = pulseCountPerFlowUnit;
}

void Flow_Pulse(Flow flow)
{
  Counter_Increment(flow->counter);
}

long Flow_GetRate(Flow flow)
{
  // Note: get measurements and restart measuring
  long endTime = Timer_GetTime(flow->timer);
  long interval = endTime - flow->startTime;
  long pulseCount = Counter_Exchange(flow->counter, 0);

  // Note: calculate rate
  long pulseCountPerSecond = pulseCount * 1000 / interval;
  long flowRate = pulseCountPerSecond / flow->pulseCountPerFlowUnit;
  flow->startTime = endTime;

  return flowRate;
}
