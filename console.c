#include "console.h"
#include <windows.h>

void Console_WaitUntilTerminated()
{
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0)) {
	DispatchMessage(&msg);
  }
}
