/*
** my_epur_str.c for my_epur_str in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Dec 24 18:28:21 2015 Ronan Boiteau
** Last update Mon Jan 18 17:28:43 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

static t_uint	_get_clean_str_size(char *str)
{
  t_uint	size;
  t_uint	idx;

  idx = 0;
  size = 0;
  while (str[size])
    {
      if (str[idx] == ' ' || str[idx] == C_TAB)
	{
	  size += 1;
	  while (str[idx] == ' ' || str[idx] == C_TAB)
	    idx += 1;
	}
      size += 1;
    }
  return (size);
}

static t_uint	_is_last(char *str)
{
  t_uint		idx;

  idx = 0;
  while (str[idx])
    {
      if (str[idx] != ' ' && str[idx] != C_TAB)
	return (FALSE);
      idx += 1;
    }
  return (TRUE);
}

static char	_get_char(const char *str,
			  int *first,
			  t_uint *idx,
			  t_uint *idx_str)
{
  char		new_letter;

  *first = FALSE;
  new_letter = str[*idx_str];
  *idx += 1;
  *idx_str += 1;
  return (new_letter);
}

static char	*_init_variables(char *str,
				 t_uint *idx,
				 t_uint *idx_str,
				 int *first)
{
  char		*clean_str;

  *first = TRUE;
  clean_str = malloc(sizeof(char) * (_get_clean_str_size(str) + 1));
  if (clean_str == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed" EOL);
  *idx = 0;
  *idx_str = 0;
  return (clean_str);
}

char		*my_epur_str(char *str)
{
  t_uint	idx_str;
  t_uint	idx;
  char		*clean_str;
  int		first;

  if (str == NULL)
    return (NULL);
  clean_str = _init_variables(str, &idx, &idx_str, &first);
  while (str[idx_str])
    {
      if (str[idx_str] == ' ' || str[idx_str] == C_TAB)
	{
	  if (first == FALSE && _is_last(str + idx_str) == FALSE)
	    {
	      clean_str[idx] = ' ';
	      idx += 1;
	    }
	  while (str[idx_str] == ' ' || str[idx_str] == C_TAB)
	    idx_str += 1;
	}
      else
	clean_str[idx] = _get_char(str, &first, &idx, &idx_str);
    }
  clean_str[idx] = C_NUL;
  return (clean_str);
}
