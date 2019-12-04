#ifndef SCHOOL21_LEVEL2_FILLIT_FH_FILLIT_H
# define SCHOOL21_LEVEL2_FILLIT_FH_FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

/*t_list	*read_single_tetrimino(int fd,  t_list **input);
t_list	*get_tetriminos(int fd);*/
// 1. just read and print all file
// 2. just read and save to t_list->content one tetromino
// 3. apply checks one by one

t_list	*get_tetriminos(int fd, t_list *input);
#endif
