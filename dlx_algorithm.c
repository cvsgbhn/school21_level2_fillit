#include "dlx_algorithm.h"

// cover

// uncover

// find column with fewest 1's: func to count sum of a column
// sum_ones, find_column

// function to check if given matrix is empty (have no nodes except root)
// int  is_empty(x_node *root)

// add to temporary solution function
// add_row

// solution
int   solution(col_obj *root, col_obj *tmp_sol)
{
    col_obj  *chosen_col;
    x_node  *next_node;
    int     row_num;
   // success = 1
   // fail = 0
   // error = -1
   if ((is_empty == 1))
       return (1);
   chosen_col = find_column(root);
   row_num = find_row(chosen_col);
   add_row(row_num, tmp_sol);
   next_node = root;
   // move from matrix header, to r each it at the end of while
   while (next_node->row_num != 1)
       next_node = next_node->right;

}