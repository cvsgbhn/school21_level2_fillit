#include "dlx_algorithm.h"

/*
 *
*/
int  dl_length(d_list *any_list)
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

/*
* find int square root
*/
int sqrt_root(int number)
{
  int   root;
  int   result;

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

    size = sqrt_root(num * 4);
    return size;
}
