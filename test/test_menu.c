// Include the test framework.
#include "vendor/unity.h"
#include <stdbool.h>

// Include the header file with the declarations of the functions you create.
#include "../src/lexer.h"

// Runs before every test.
void setUp(void) {}

// Runs after every test.
void tearDown(void) {}

// Defines a single test.
void test_is_char_a_separator(void)
{
  int res = is_a_char_separator('/');
  TEST_ASSERT_TRUE(res);
}

void test_is_string_a_separator(void)
{
  int res = is_a_string_separator("==");
  TEST_ASSERT_TRUE(res);
}
