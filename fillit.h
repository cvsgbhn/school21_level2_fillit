#ifndef SCHOOL21_LEVEL2_FILLIT_FH_FILLIT_H
# define SCHOOL21_LEVEL2_FILLIT_FH_FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

d_list	*get_tetrominos(int fd);
void print_linked_list(t_list *head);

#endif
