#include <stdio.h>

#include "timerImpl.h"
#include "counterImpl.h"
#include "flow.h"
#include "flowSensor.h"

struct TimerStruct timer;
struct CounterStruct counter;
struct FlowStruct flow;

void Pulse()
{
  Flow_Pulse(&flow);
}

void DisplayFlowRate()
{
  printf("%d\n", Flow_GetRate(&flow));
}

int main()
{
  Timer_Create(&timer);
  Counter_Create(&counter);
  Flow_Create(&flow, &counter, &timer, 1); // 1 pulse = 1 keypress / second

  Timer_SetIntervalAlarm(&timer, 5 * 1000, DisplayFlowRate);
  FlowSensor_Listen(Pulse);

  printf("Press ctrl-c to exit...\n");
  Console_WaitUntilTerminated();

  return 0;
}
