/*
** my_uitoa.c for my_uitoa in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Sun Jan 31 17:50:05 2016 Ronan Boiteau
** Last update Sun Jan 31 23:54:03 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

static char	_count_digits(t_uint nbr)
{
  if (nbr < 10)
    return (1);
  else if (nbr < 100)
    return (2);
  else if (nbr < 1000)
    return (3);
  else if (nbr < 10000)
    return (4);
  else if (nbr < 100000)
    return (5);
  else if (nbr < 1000000)
    return (6);
  else if (nbr < 10000000)
    return (7);
  else if (nbr < 100000000)
    return (8);
  else if (nbr < 1000000000)
    return (9);
  else
    return (10);
}

char		*my_uitoa(t_uint nbr)
{
  char		*str;
  char		size;
  int		idx;

  size = _count_digits(nbr);
  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed" EOL);
  idx = 0;
  str[idx] = '0';
  str[idx + 1] = C_NUL;
  while (size > 0)
    {
      str[idx] = ((nbr / my_power(10, size - 1))
		  - (my_atoi(str) * 10)) + '0';
      idx += 1;
      str[idx] = C_NUL;
      size -= 1;
    }
  return (str);
}
