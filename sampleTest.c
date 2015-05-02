#include "sample.h"

TEST_GROUP(Sample); 

TEST_SETUP(Sample) 
{ 
} 
TEST_TEAR_DOWN(Sample) 
{ 
}


TEST(Sample, Simple)
{
  int expected = 0x180;
  int actual = SetBit(SetBit(0, 7), 8);
  TEST_ASSERT_EQUAL_HEX16(expected, actual);
}

TEST(Sample, IsDigits)
{
  TEST_ASSERT_TRUE(IsDigits("10"));
  TEST_ASSERT_TRUE(IsDigits("01"));
  TEST_ASSERT_TRUE(IsDigits("17983472938729347293874239"));
  TEST_ASSERT_TRUE(IsDigits("1"));
  TEST_ASSERT_FALSE(IsDigits(0));
  TEST_ASSERT_FALSE(IsDigits(""));
  TEST_ASSERT_FALSE(IsDigits("a"));
  TEST_ASSERT_FALSE(IsDigits("0x0"));
  TEST_ASSERT_FALSE(IsDigits("-10"));
  TEST_ASSERT_FALSE(IsDigits("1.0"));
  TEST_ASSERT_FALSE(IsDigits("1 0"));
  TEST_ASSERT_FALSE(IsDigits(".0"));
}

TEST_GROUP_RUNNER(Sample)
{
  RUN_TEST_CASE(Sample, Simple);
  RUN_TEST_CASE(Sample, IsDigits);
}

























/*

TEST(Sample, IsDigits)
{
  TEST_ASSERT_TRUE(IsDigits("123456790"));
  TEST_ASSERT_FALSE(IsDigits("abc"));
  TEST_ASSERT_FALSE(IsDigits("abc123"));
  TEST_ASSERT_FALSE(IsDigits("123.45"));
  TEST_ASSERT_FALSE(IsDigits(""));
  TEST_ASSERT_FALSE(IsDigits(0));
}

  // RUN_TEST_CASE(Sample, IsDigits);
*/

