# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "fillit.h"

int	get_one_tetrimino(t_list **new_element, int fd, size_t letter)
{
	char	*tmp_line;
	char 	*main_line;
	int 	counter;

	main_line = "";
	counter = 0;
	while (counter <= 4)
	{
		if(!(get_next_line(fd, &tmp_line)))
		// + check tmp_line
			break ;
		main_line = ft_strjoin(main_line, tmp_line);
		main_line = ft_strjoin(main_line, "\n");
		counter++;
	}
	if (counter < 4)
	{
		//free(tmp_line);
		return (0);
	}
    (*new_element)->content = ft_strdup(main_line);
    (*new_element)->content_size = letter;
	return (1);
}

t_list	*get_tetriminos(int fd)
{
	t_list	*tmp_list;
	t_list  *next_list;
	t_list	*head;
	size_t  letter_num;

	letter_num = 1;
	tmp_list = ft_lstnew("\0", 0);
	head = tmp_list;
	while ((get_one_tetrimino(&tmp_list, fd, letter_num)))
    {
	    next_list = ft_lstnew("\0", 0);
	    ft_lstadd_toend(&tmp_list, next_list);
	    tmp_list = tmp_list->next;

    }
	printf("%s\n", ":-) got one tetromino");

	return (head);
}