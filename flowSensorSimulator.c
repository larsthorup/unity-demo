#include "flowSensor.h"
#include <windows.h>

static FlowSensor_Pulse pulse;
static HHOOK keyboard_hook;
static HINSTANCE console_module;

LRESULT CALLBACK keyboard_hook_proc(int code, WPARAM wParam, LPARAM lParam)
{
  if(wParam == WM_KEYDOWN) pulse();
  return CallNextHookEx(keyboard_hook, code, wParam, lParam);
}

void FlowSensor_Listen(FlowSensor_Pulse p)
{
  pulse = p;
  console_module = GetModuleHandle(NULL);
  keyboard_hook = SetWindowsHookEx( WH_KEYBOARD_LL, keyboard_hook_proc, console_module, 0 );
  if(keyboard_hook == NULL)
	{
	  printf("SetWindowsHookEx failed");
	}
}
