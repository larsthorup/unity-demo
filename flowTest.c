#include "timerStub.h"
#include "counterImpl.h"
#include "flow.h"

TEST_GROUP(Flow);

struct TimerStruct timer;
struct CounterStruct counter;
struct FlowStruct flow;
int i;

TEST_SETUP(Flow)
{
  Timer_Create(&timer);
  Counter_Create(&counter);
  Flow_Create(&flow, &counter, &timer, 200 / 10);
}

TEST_TEAR_DOWN(Flow)
{
}

TEST(Flow, Stable)
{
  // invoke
  Timer_SetTime(&timer, 0);
  for(i = 0; i < 50; ++i) 
	{
	  Timer_SetTime(&timer, i*10);
	  Flow_Pulse(&flow);
	}
	
  // verify
  TEST_ASSERT_EQUAL(5, Flow_GetRate(&flow));
}

TEST(Flow, AllAtOnce)
{
  // invoke
  Timer_SetTime(&timer, 0);
  for(i = 0; i < 70; ++i) Flow_Pulse(&flow);
  Timer_SetTime(&timer, 500);
	
  // verify
  TEST_ASSERT_EQUAL(7, Flow_GetRate(&flow));
}

TEST_GROUP_RUNNER(Flow)
{
  RUN_TEST_CASE(Flow, AllAtOnce);
  RUN_TEST_CASE(Flow, Stable);
}
