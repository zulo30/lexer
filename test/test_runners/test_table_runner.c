/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum)                                        \
  {                                                                            \
    Unity.CurrentTestName = #TestFunc;                                         \
    Unity.CurrentTestLineNumber = TestLineNum;                                 \
    Unity.NumberOfTests++;                                                     \
    if (TEST_PROTECT()) {                                                      \
      setUp();                                                                 \
      TestFunc();                                                              \
    }                                                                          \
    if (TEST_PROTECT()) {                                                      \
      tearDown();                                                              \
    }                                                                          \
    UnityConcludeTest();                                                       \
  }

/*=======Automagically Detected Files To Include=====*/
#include "../../src/utils/table.h"
#include "../vendor/unity.h"

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_create_table(void);

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test/test_table.c");
  RUN_TEST(test_create_table, 13);

  return (UnityEnd());
}
