#include "dlx_algorithm.h"

// cover
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
// uncover
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
// find column with fewest 1's: func to count sum of a column
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

// solution
int   search(col_obj *root, col_obj *tmp_sol)
{
    col_obj *c_col;
    col_obj *copy;
    x_node *travel;
    x_node *pin;

    copy = &root;
    if (root->next == root) {
        modify_solution(&tmp_sol);
        return (1);
    }
    c_col = find_column(copy); // where root->size is min but != 0
    travel = c_col->list_header;
    cover(c_col);
    // traverse down, in each step traverse right, cover every column, where object exists
    while (travel != travel->C) {
        travel = travel->down;
        pin = travel;
        while (travel->right != pin) {
            cover(travel->C);
            travel = travel->right;
        }
        search(root);
        travel = pin;
        pin = travel->C;
        while (travel != pin) {
            uncover(travel);
            travel = travel->left;
        }
        uncover(pin);
    }
    uncover(pin);
    return (0);
}