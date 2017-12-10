/*
** my_envcpy.c for my_envcpy in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Jan  3 18:38:45 2016 Ronan Boiteau
** Last update Mon Jan 18 16:36:38 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

char		**my_envcpy(char **env)
{
  t_uint	idx_line;
  char		**env_cpy;

  idx_line = 0;
  while (env != NULL && env[idx_line])
    idx_line += 1;
  if ((env_cpy = malloc(sizeof(char *) * (idx_line + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed" EOL);
  idx_line = 0;
  while (env != NULL && env[idx_line])
    {
      env_cpy[idx_line] = my_strdup(env[idx_line]);
      idx_line += 1;
    }
  env_cpy[idx_line] = C_NUL;
  return (env_cpy);
}
