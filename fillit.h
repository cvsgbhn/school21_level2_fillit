#ifndef SCHOOL21_LEVEL2_FILLIT_FH_FILLIT_H
# define SCHOOL21_LEVEL2_FILLIT_FH_FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

//defining tetromino samples
// H - horizontal, V - vertical
// L - left, R - right
#define T_SQUARE (int[4]) {0,1,5,6}
#define T_LINE_H (int[4]) {0,1,2,3}
#define T_LINE_V (int[4]) {0,5,10,15}
#define T_SFIG_VL (int[4]) {0,5,6,11}
#define T_SFIG_VR (int[4]) {1,5,6,10}
#define T_SFIG_HL (int[4]) {0,1,6,7}
#define T_SFIG_HR (int[4]) {1,2,5,6}
#define T_TFIG_H1 (int[4]) {0,1,2,6}
#define T_TFIG_H2 (int[4]) {1,5,6,7}
#define T_TFIG_VL (int[4]) {0,5,6,10}
#define T_TFIG_VR (int[4]) {1,5,6,11}
#define T_LFIG_VL (int[4]) {0,5,10,11}
#define T_LFIG_VR ()
/*t_list	*read_single_tetrimino(int fd,  t_list **input);
t_list	*get_tetriminos(int fd);*/
// 1. just read and print all file
// 2. just read and save to t_list->content one tetromino
// 3. apply checks one by one

d_list	*get_tetriminos(int fd);
void print_linked_list(t_list *head);
#endif
