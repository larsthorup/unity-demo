#include "counter.h"
#include "timer.h"

typedef struct FlowStruct
{
  Timer timer;
  Counter counter;
  long pulseCountPerFlowUnit;
  long startTime;
} *Flow;

void Flow_Create(Flow, Counter, Timer, long pulseCountPerFlowUnit);

void Flow_Pulse(Flow);

long Flow_GetRate(Flow);
