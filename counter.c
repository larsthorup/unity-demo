#include "counterImpl.h"

void Counter_Create(Counter counter)
{
  Counter_Exchange(counter, 0);
}
void Counter_Increment(Counter counter)
{
  InterlockedIncrement(&counter->value);
}
long Counter_Exchange(Counter counter, long newValue)
{
  return InterlockedExchange(&counter->value, newValue);
}
