// Include the test framework.
#include "vendor/unity.h"

// Include the header file with the declarations of the functions you create.
#include "../src/utils/queue.h"

// Runs before every test.
void setUp(void) {}

// Runs after every test.
void tearDown(void) {}

// Defines a single test.
void test_enqueue_item(void)
{
  struct Queue *queue = createQueue(5);
  int res = enqueue(queue, 'a');

  TEST_ASSERT_TRUE(res);
}

void test_dequeue_item(void)
{
  struct Queue *queue = createQueue(5);
  enqueue(queue, 'a');
  int res = dequeue(queue);

  TEST_ASSERT_TRUE(res);
}
void test_if_queue_is_empty(void)
{
  struct Queue *queue = createQueue(5);

  TEST_ASSERT_TRUE(isEmpty(queue));
}
void test_if_queue_is_full(void)
{
  struct Queue *queue = createQueue(1);
  enqueue(queue, 'a');

  TEST_ASSERT_TRUE(isFull(queue));
}
void test_dequeue_all(void)
{
  struct Queue *queue = createQueue(6);

  enqueue(queue, 'a');
  enqueue(queue, 'b');
  enqueue(queue, 'c');
  enqueue(queue, 'd');
  enqueue(queue, 'f');

  char *actual = dequeue_all(queue);
  char *expected = "abcdf";

  TEST_ASSERT_EQUAL_STRING(expected, actual);
}
