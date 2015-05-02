#include "counter.h"
#include <windows.h>

struct CounterStruct
{
  LONG volatile value;
};
