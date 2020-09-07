// Include the standard definitions header from the standard library, so that we
// have access to 'NULL'. This can be removed if your changes remove the need
// for 'NULL'.
#include <stdio.h>
#include <stddef.h>

#include "./vendor/fort.h"
#include "table.h"

// Define the function itself.
const char *create_table(void)
{
   
   ft_table_t *table = ft_create_table();
   /* Set "header" type for the first row */
   ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);

   ft_write_ln(table, "N", "Driver", "Time", "Avg Speed");

   ft_write_ln(table, "1", "Ricciardo", "1:25.945", "222.128");
   ft_write_ln(table, "2", "Hamilton", "1:26.373", "221.027");
   ft_write_ln(table, "3", "Verstappen", "1:26.469", "220.782");

   printf("%s\n", ft_to_string(table));
   ft_destroy_table(table);

   return "Hello, World!";
}
