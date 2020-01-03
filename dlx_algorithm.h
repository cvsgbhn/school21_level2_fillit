//
// Created by ubuntuser on 02.01.2020.
//

#ifndef SCHOOL21_LEVEL2_FILLIT_DLX_ALGORITHM_H
# define SCHOOL21_LEVEL2_FILLIT_DLX_ALGORITHM_H
# include "libft/libft.h"

typedef struct          data_object
{
    struct data_object  *left;
    struct data_object  *right;
    struct data_object  *up;
    struct data_object  *down;
    struct data_object  *C;
    int                 row_num;
}                       x_node;

typedef struct column_object
{
    x_node  list_header;
    int     size;
    char    name;
    int     number;
}           col_obj;

#endif //SCHOOL21_LEVEL2_FILLIT_DLX_ALGORITHM_H
