#include "timerImpl.h"
#include <windows.h>

void Timer_Create(Timer timer)
{
}

long Timer_GetTime(Timer timer)
{
  return GetTickCount();
}

static Timer_AlarmProc alarmProc;

VOID CALLBACK timer_proc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
  alarmProc();
}

void Timer_SetIntervalAlarm(Timer timer, long ms, Timer_AlarmProc proc)
{
  alarmProc = proc; // ToDo: handle multiple alarmProcs by storing this value in the timer object and looking it up in timer_proc()
  if(SetTimer(0, 0, ms, timer_proc) == 0)
	{
	  printf("SetTimer failed");
	  exit(1);
	}
}
