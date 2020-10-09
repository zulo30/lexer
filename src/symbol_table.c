// Include the standard definitions header from the standard library, so that we
// have access to 'NULL'. This can be removed if your changes remove the need
// for 'NULL'.
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "./utils/table.h"
#include "./vendor/cjson.h"
#include "./vendor/fort.h"

#define JSON_PATH "./data/symbol_table.json"

// Define the function itself.
const char *load_symbol_table(void)
{
  FILE *fp = fopen(JSON_PATH, "r");
  if (!fp) {
    perror("File opening failed");
  }
  char *json = (char *)malloc(12705 * sizeof(char));

  int i = 0;
  int c; // note: int, not char, required to handle EOF
  while ((c = fgetc(fp)) != EOF) { // standard C I/O file reading loop
    json[i] = c;
    i++;
  }

  if (ferror(fp))
    puts("I/O error when reading");
  else if (feof(fp))
    puts("the table of symbols was loaded successful ...!");

  fclose(fp);

  return json;
}

const char *print_symbol_table(void)
{
  const cJSON *symbols = NULL;
  const cJSON *symbol = NULL;

  char *s = NULL;

  const char *json = load_symbol_table();
  cJSON *symbol_table_json = cJSON_Parse(json);

  symbols = cJSON_GetObjectItemCaseSensitive(symbol_table_json, "symbol_data");

  ft_table_t *table = ft_create_table();
  /* Set border style */
  ft_set_border_style(table, FT_BASIC_STYLE);

  ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);

  ft_write_ln(table, "Nombre", "Tipo");

  cJSON_ArrayForEach(symbol, symbols)
  {
    const cJSON *types = NULL;
    const cJSON *type = NULL;

    const cJSON *sym = cJSON_GetObjectItemCaseSensitive(symbol, "symbol");
    types = cJSON_GetObjectItemCaseSensitive(symbol, "type");

    s = cJSON_Print(sym);
    for (type = (types != NULL) ? (types)->child : NULL; type != NULL;
         type = type->next)

    {
      const char *first_child_element = types->child->valuestring;
      const char *type_element = type->valuestring;
      if (strcmp(first_child_element, type_element) == 0) {
        ft_write_ln(table, s, cJSON_Print(type));
      }
      else {
        ft_write_ln(table, "", cJSON_Print(type));
      }
    }

    ft_add_separator(table);
  }
  cJSON_Delete(symbol_table_json);
  const char *str_table = ft_to_string(table);
  printf("%s", str_table);
  ft_destroy_table(table);
  return str_table;
}
