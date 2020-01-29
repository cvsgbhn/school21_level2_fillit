#include "dlx_algorithm.h"

/*
* Cover action according to Knuth's paper 'Dancing links'
*/
void    cover(col_obj *column)
{
    x_node  *x_obj;
    x_node  *x_side;
    x_node  *x_row;

    x_obj = column->list_header;
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
    column->list_header.left->right = column->list_header;
    column->list_header.right->left = column->list_header;
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

// solution
int   search(x_node *root, x_node *tmp_sol, int level)
{
    x_node  *x_right;
    x_node  *x_left;
    x_node  *x_travel;
    col_obj *column;
    int     x_name;

    x_name = x_travel->letter;
    if (x_right->right == &root)
        return 1;
    column = x_right->C;
    x_travel = column->list_header;
    cover(&column);
    while(x_travel->down != column->list_header)
    {
        add_to_solution(&tmp_sol, &x_travel);
        x_right = x_travel->right;
        while(x_right->right != x_travel)
        {
            cover(x_right->C);
            x_right = x_right->right;
        }
        x_travel = x_travel->down;

    }
}
