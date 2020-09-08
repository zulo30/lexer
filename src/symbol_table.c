// Include the standard definitions header from the standard library, so that we
// have access to 'NULL'. This can be removed if your changes remove the need
// for 'NULL'.
#include <stddef.h>
#include <stdio.h>

#include "./utils/table.h"
#include "./vendor/fort.h"

// Define the function itself.
const char *load_symbol_table(void) { return "Hello, World!"; }
