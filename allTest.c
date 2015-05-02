#include "unity/unity_fixture.h"
#include "sampleTest.c"
#include "flowTest.c"

static void runAllTests()
{
  RUN_TEST_GROUP(Sample);
  RUN_TEST_GROUP(Flow);
}

int main(int argc, char* argv[])
{
  return UnityMain(argc, argv, runAllTests);
}
