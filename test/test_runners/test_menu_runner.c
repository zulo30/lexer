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
#include "../../src/lexer.h"
#include "../vendor/unity.h"

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_is_char_a_separator(void);
extern void test_is_string_a_separator(void);

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
  UnityBegin("test/test_menu.c");
  RUN_TEST(test_is_char_a_separator, 14);
  RUN_TEST(test_is_string_a_separator, 21);

  return (UnityEnd());
}
