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
int   search(col_obj *root, col_obj *tmp_sol)
{
    col_obj *c_col;
    col_obj *copy;

    copy = &root;
    if (root->next == root)
    {
        modify_solution(&tmp_sol);
        return (1);
    }
    c_col = find_column(copy); // where root->size is min but != 0
    cover(c_col);
    // traverse down, in each step traverse right, cover every column, where object exists
    while (c_col->)



}