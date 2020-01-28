# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "fillit.h"

/*
 * this funciton takes existing DDL and adds to it one by one new elements with written tetrominoes
 */
d_list	*get_tetrominos(int fd)
{
	d_list	*tmp_list;
	d_list  *next_list;
	d_list	*head;
	size_t  letter_num;

	letter_num = 65;
	tmp_list = ft_doubly_linked_lstnew("\0", 0);
	head = tmp_list;
	while ((get_one_tetromino(&tmp_list, fd, letter_num)))
  {
    next_list = ft_doubly_linked_lstnew("\0", 0);
    ft_doubly_linked_lstadd_toend(&tmp_list, next_list);
	  tmp_list = tmp_list->next;
	  letter_num ++;
  }
	// test printf, never mind
	printf("%s\n", ":-) got one tetromino");


	return (head);
}
