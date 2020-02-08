//
// Created by ubuntuser on 02.01.2020.
//

#ifndef SCHOOL21_LEVEL2_FILLIT_DLX_ALGORITHM_H
# define SCHOOL21_LEVEL2_FILLIT_DLX_ALGORITHM_H
# include "../libft/libft.h"


typedef struct column_object
{
    //x_node  list_header;
    int     size;
    int     x; // board coord x
    int     y; // board coord y
}           col_obj;

typedef struct          data_object
{
    struct data_object  *left;
    struct data_object  *right;
    struct data_object  *up;
    struct data_object  *down;
    col_obj             *C;
    int                 letter;
    int                 row_num;
}                       x_node;


/*
 * dlx_structure_routine.c
*/
void    connect_vertical(x_node *x_new, x_node *column);
void    add_to_board(int name, int x[4], int y[4], x_node *root);
void add_all_tetromino_positions(d_list *tetro, x_node *root, int square_size);
void	ft_xnode_add_toend(x_node* head_ref, x_node *new_node);
x_node  *create_xnode_list(int size, int letter);
void    create_headers_list(x_node *root, int size);
x_node  *create_x_node(int letter_num);
col_obj *create_col_obj(x_node *obj, int x, int y);

/*
 * dlx_algorithm.c
*/
void    cover(x_node *list_header);
void    uncover(x_node *x_obj);
int   search(x_node *root, x_node *tmp_sol, int level, int x_name);

#endif
