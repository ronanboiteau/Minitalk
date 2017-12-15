#include <stdlib.h>
#include "my.h"

char		*my_realloc(char *str, t_uint new_size)
{
  char		*new_str;

  if ((new_str = malloc(sizeof(char) * (new_size + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed\n");
  my_strncpy(new_str, str, my_strlen(str));
  return (new_str);
}
