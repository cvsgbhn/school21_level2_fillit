#include "dlx_algorithm.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "fillit.h"
/*
 *
*/
/*int  dl_length(d_list *any_list)
{
  int counter;

  counter = 1;
  while(any_list->next != NULL)
  {
    any_list = any_list->next;
    counter++;
  }
  return counter;
}
*/
/*
* find int square root
*/
int sqrt_root(int number)
{
  int   root;
  int   result;
  printf("ENTERED basic_calculations.c/sqrt_root :28");

  root = 1;
  result = 1;
  if (number == 0 || number == 1)
  return number;
  while (result <= number)
  {
    root++;
    result = root * root;
  }
  return root - 1;
}

/*
* find size of the board
*/
int find_field_size(int tetro_num)
{
    int     size;
    printf("ENTERED basic_calculations.c/find_field_size :48");

    size = sqrt_root(tetro_num * 4);
    return size;
}
