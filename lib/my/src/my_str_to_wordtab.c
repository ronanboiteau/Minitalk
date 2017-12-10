/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/boitea_r
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Thu Dec 24 18:26:48 2015 Ronan Boiteau
** Last update Mon Jan 18 17:32:39 2016 Ronan Boiteau
*/

#include "my.h"
#include <stdlib.h>

static t_uint	_get_word_size(char *str)
{
  t_uint	size;

  size = 0;
  while (str[size] && str[size] != ' ' && str[size] != C_TAB)
    size += 1;
  return (size);
}

static t_uint	_count_words(char *str)
{
  t_uint	idx;
  t_uint	words;

  words = 0;
  idx = 0;
  while (str[idx])
    {
      if (str[idx] == ' ' || str[idx] == C_TAB)
	words += 1;
      while (str[idx] == ' ' || str[idx] == C_TAB)
	idx += 1;
      idx += 1;
    }
  return (words + 1);
}

static char	*_fill_column(char *clean_str, t_uint *idx_str)
{
  t_uint	idx;
  t_uint	size;
  char		*column;

  size = _get_word_size(clean_str + *idx_str);
  if ((column = malloc(sizeof(char) * (size + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed" EOL);
  idx = 0;
  while (idx < size && clean_str[*idx_str])
    {
      column[idx] = clean_str[*idx_str];
      *idx_str += 1;
      idx += 1;
    }
  column[idx] = C_NUL;
  *idx_str += 1;
  return (column);
}

char		**my_str_to_wordtab(char *clean_str)
{
  t_uint	idx_line;
  t_uint	idx_str;
  t_uint	words;
  char		**tab;

  if (clean_str == NULL)
    return (NULL);
  words = _count_words(clean_str);
  if ((tab = malloc(sizeof(char *) * (words + 1))) == NULL)
    my_exit(EXIT_FAILURE, "ERROR: Out of memory! malloc() failed" EOL);
  idx_str = 0;
  idx_line = 0;
  while (idx_line < words)
    {
      tab[idx_line] = _fill_column(clean_str, &idx_str);
      idx_line += 1;
    }
  tab[idx_line] = C_NUL;
  return (tab);
}
