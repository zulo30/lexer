// table_symbols size 11030

#include "./utils/queue.h"
#include "./utils/table.h"
#include "./vendor/cjson.h"
#include "./vendor/fort.h"
#include <stdio.h>

int main(void)
{
  const cJSON *symbols = NULL;
  const cJSON *symbol = NULL;
  char *sn = NULL;

  FILE *fp = fopen("./data/symbol_table.json", "r");
  if (!fp) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }
  char json[11047];

  int i = 0;
  int c; // note: int, not char, required to handle EOF
  while ((c = fgetc(fp)) != EOF) { // standard C I/O file reading loop
    json[i] = c;
    i++;
  }

  if (ferror(fp))
    puts("I/O error when reading");
  else if (feof(fp))
    puts(" the file was readed successfully  :)");

  cJSON *symbol_table_json = cJSON_Parse(json);

  symbols = cJSON_GetObjectItemCaseSensitive(symbol_table_json, "SymbolsData");
  cJSON_ArrayForEach(symbol, symbols)
  {
    const cJSON *name = cJSON_GetObjectItemCaseSensitive(symbol, "Name");
    sn = cJSON_Print(name);
    printf("Symbol: %s \n", sn);
  }

  fclose(fp);
  cJSON_Delete(symbol_table_json);
  return 0;
}
