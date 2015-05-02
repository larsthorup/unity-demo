#include "sample.h"

int SetBit(int value, int bitNumber)
{
  return value | (1 << bitNumber );
}

int IsDigits(const char* s)
{
  int i;
  if(s == 0) return 0;
  if(strlen(s) == 0) return 0;
  for(i = 0; i < strlen(s); ++i)
	{
	  if(s[i] < '0' || s[i] > '9')
		{
		  return 0;
		}
	}
  return 1;
}




























/*
int IsDigits(char* s)
{
  int i;
  if(s == 0) return 0;
  if(strlen(s) == 0) return 0;
  for(i = 0; i < strlen(s); ++i)
	{
	  if(s[i] < '0' || s[i] > '9')
		{
		  return 0;
		}
	}
  return 1;
}
*/
