// table_symbols size 11030

// #include "./utils/queue.h"
// #include "./utils/table.h"
// #include "./vendor/cjson.h"
// #include "./vendor/fort.h"
#include "./symbol_table.h"
#include <stdio.h>

int main(void)
{
  const char *res = print_symbol_table();
  printf("%s", res);
}
