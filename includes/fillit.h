#ifndef SCHOOL21_LEVEL2_FILLIT_FH_FILLIT_H
# define SCHOOL21_LEVEL2_FILLIT_FH_FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "dlx_algorithm.h"


/*
 * preparing_routine.c
*/
void    coords_rollback(int last, int xory[4]);
int    move_tetromino_once(int square_size, int x_coords[4], int y_coords[4]);
int     *find_old_coordinates(char *tetromino);
int   *parse_to_xy(int coords[8], char xory);
int     min_in_array(int *numbers);
int   *find_new_coordinates(int *xory_coords);
int count_not_symbol(char symb, char *str);
int	check_one_tetrostring(char *string);
int	get_one_tetromino(d_list **new_element, int fd, size_t letter);
d_list	*get_tetrominos(int fd);
int     dl_length(d_list *input_lst);

/*
 * basic_calculations.c
*/
int sqrt_root(int number);
int find_field_size(int tetro_num);

/*
 * fillit.c
*/
void	transformate(x_node *result, char **matrix);
void	print_result(x_node *result, int size);
int main(int argc, char **argv);

#endif
