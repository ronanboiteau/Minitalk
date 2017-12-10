/*
** my_realloc.c for server in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Feb 11 23:56:46 2016 Ronan Boiteau
** Last update Thu Feb 11 23:58:13 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

char		*my_realloc(char *str, t_uint new_size)
{
  char		*new_str;

  if ((new_str = malloc(sizeof(char) * (new_size + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed" EOL);
  my_strncpy(new_str, str, my_strlen(str));
  return (new_str);
}
