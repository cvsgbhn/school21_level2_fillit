#include "dlx_algorithm.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "fillit.h"
/*
* Cover action according to Knuth's paper 'Dancing links'
*/
void    cover(x_node *list_header)
{
    x_node  *x_obj;
    x_node  *x_side;
    x_node  *x_row;
    col_obj *column;

    column = list_header->C;
    x_obj = list_header;
    x_side = x_obj->left;
    x_side->right = x_obj->right;
    x_side = x_obj->right;
    x_side->left = x_obj->left;

    x_side = x_obj->down;
    x_row = x_side->right;
    while (x_side != x_obj)
    {
        while (x_row != x_side)
        {
            // is it legal to do??
            x_row->up->down = x_row->down;
            x_row->down->up = x_row->up;
            x_row = x_row->right;
        }
        column->size = column->size - 1;
        x_side = x_side->down;
    }
}

/*
* Unover action according to Knuth's paper 'Dancing links'
*/
void    uncover(x_node *x_obj)
{
    x_node  *x_col;
    x_node  *x_row;
    x_node  *x_line;
    col_obj *column;

    x_col = x_obj->up;
    x_row = x_obj->left;
    column = x_obj->C;
    while (x_col != x_obj)
    {
        while (x_row != x_col)
        {
            column->size++;
            x_row->up->down = x_row;
            x_row->down->up = x_row;
            x_row = x_row->left;
        }
        x_line = x_line->up;
    }
    //column->list_header.left->right = column->list_header;
    //column->list_header.right->left = column->list_header;
}


/*
*
find column with fewest 1's: func to count sum of a column
but it appears that moulinette thinks another way
col_obj find_column(col_obj *root)
{
    int     min;
    x_node  *header;
    col_obj *column;
    col_obj *min_column;

    header = root->list_header.right;
    min_column = column;
    min = column->size;
    while (header != root->list_header)
    {
        column = header->C;
        if (column->size < min)
        {
            min = column->size;
            min_column = column;
        }
        header = header->right;
    }
    return (min_column);
}
*/


/*
 * adding to solution matrix
*/
void add_to_solution(x_node *tmp_sol, x_node *row)
{
  x_node *last;

  last = tmp_sol;
  row->down = tmp_sol;

  if (tmp_sol == NULL)
  {
    row->down = row;
    tmp_sol = row;
    return;
  }

  while (last->down != tmp_sol)
    last = last->down;

  last->down = row;
  row->up = last;
  return;
}

/*
 * removing from solution matrix
*/
void remove_from_solution(x_node *tmp_sol, x_node *row)
{
  x_node *x_travel;

  x_travel = tmp_sol;
  while(x_travel != row)
    x_travel = x_travel->down;
  if (tmp_sol == x_travel)
  {
    tmp_sol = NULL;
    x_travel->down = tmp_sol;
    x_travel->up = NULL;
    x_travel->down = NULL;
    return;
  }
  x_travel->up->down = x_travel->down;
  x_travel->down = x_travel->up;
  x_travel->up = NULL;
  x_travel->down = NULL;
}

/*
 * solution
 * x_name originally should be sent as 0
*/
int   search(x_node *root, x_node *tmp_sol, int level, int x_name)
{
    x_node  *x_right;
    x_node  *x_left;
    x_node  *x_travel;
    x_node  *x_fixed;
    //col_obj *column;

    if (tmp_sol->up->letter == root->left->letter)
        return (1);
    x_right = root->right;
    //column = x_right->C;
    x_travel = x_right;
    x_fixed = x_right;
    cover(x_right);
    while(x_travel->down != x_fixed)
    {
        if (x_name != x_travel->letter)
        {
          add_to_solution(tmp_sol, x_travel);
          x_right = x_travel->right;
          while(x_right->right != x_travel)
          {
              cover(x_fixed);
              x_right = x_right->right;
          }
          search(root, tmp_sol, level++, x_travel->letter);
          remove_from_solution(tmp_sol, x_travel);
          x_fixed = x_travel;
          //column = x_travel->C;
          x_left = x_travel->left;
          while(x_left->left != x_travel)
          {
            uncover(x_left);
            x_left = x_left->left;
          }
        }
          x_travel = x_travel->down;
    }
    return (0);
}
