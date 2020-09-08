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
#include "../../src/utils/queue.h"
#include "../vendor/unity.h"

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_enqueue_item(void);
extern void test_dequeue_item(void);
extern void test_if_queue_is_full(void);
extern void test_if_queue_is_empty(void);
extern void test_dequeue_all(void);

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
  UnityBegin("test/test_queue.c");
  RUN_TEST(test_enqueue_item, 14);
  RUN_TEST(test_dequeue_item, 22);
  RUN_TEST(test_if_queue_is_empty, 30);
  RUN_TEST(test_if_queue_is_full, 36);
  RUN_TEST(test_dequeue_all, 43);

  return (UnityEnd());
}
