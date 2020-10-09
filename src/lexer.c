// table_symbols size 11030

// #include "./utils/queue.h"
// #include "./utils/table.h"
// #include "./vendor/cjson.h"
// #include "./vendor/fort.h"
#include "./symbol_table.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// bool is_terminated = false;
int is_a_char_separator(char a)
{
  char separator_list[6] = {'.', '+', '-', '/', '*', '/'};
  int size = sizeof separator_list / sizeof *separator_list;

  bool res = false;
  for (int i = 0; i < size; i++) {
    res = res || (a == separator_list[i]) ? true : false;
  }
  return res;
}
int is_a_string_separator(char str[]) { return (strcmp(str, "==") == 0); }

void print_menu()
{
  printf("\033[1;34m");
  printf("<<<<<<<<<<<<<<<<<<< MENU >>>>>>>>>>>>>>>>>>>>>>>>> \n");
  printf("\t 1). print the table of symbols \n");
  printf("\t 2). print the tokens table\n");
  printf("\t 3). show all the arithmetic expressions\n");
  printf("\t 4). analyze expression\n");
  printf("\t 5). re-organize the arithmetic expressions\n");
  printf("\t 6). read another file\n");
  printf("\t 7). exit\n");
  printf("\033[0m");
}
void _log_unimplemented_code(char *code)
{
  printf("\033[1;31m");
  printf(" (!) Error: function unimplemented %s", code);
  printf("\033[0m");
}
//! TODO:  UNIMPLEMENTED
void _print_symbol_table(char *code)
{
  const char *res = print_symbol_table();
  printf("%s", res);
  printf("%s", code);
}
//! TODO:  UNIMPLEMENTED
void _print_tokens_table(char *code) { _log_unimplemented_code(code); }
//! TODO:  UNIMPLEMENTED
void _print_arithmetic_sentence(char *code) { _log_unimplemented_code(code); }
//! TODO:  UNIMPLEMENTED
void _expression_analyzer(char *code) { _log_unimplemented_code(code); }

void _log_unimplemented()
{
  printf("\033[1;31m");
  printf(" (!) Error: function unimplemented");
  printf("\033[0m");
}
//! TODO:  UNIMPLEMENTED
void _read_another_file() { _log_unimplemented(); }

//! TODO:  UNIMPLEMENTED
void choose_action(int choice, char *code)
{
  switch (choice) {
  case 1:
    _print_symbol_table(code);
    break;
  case 2:
    _print_tokens_table(code);
    break;
  case 3:
    _print_arithmetic_sentence(code);
    break;
  case 4:
    _expression_analyzer(code);
    break;
  case 6:
    _read_another_file();
    break;
  default:
    printf("please enter a valid choice. ");
  }
}

void cli(int argc, char *argv[])
{
  char file_name[20];
  printf("Please enter the name of the file you want to read: ");
  scanf("%s", file_name);
  printf("File = %s \n", file_name);

  if (argc <= 1) {
    print_menu();
    char *code = "";
    printf("    Enter your choice:       ");
    int choice = 0;
    scanf("%i", &choice);
    choose_action(choice, code);
  }
  else {
    printf("there are %d and the 1st argument is the %s", argc, argv[1]);
  }
}
