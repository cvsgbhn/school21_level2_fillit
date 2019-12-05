# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "fillit.h"

t_list	get_one_tetrimino(t_list *new_element, int fd)
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
		printf("%s\n%s", "got tmp_line", tmp_line);
		main_line = ft_strjoin(main_line, tmp_line);
		main_line = ft_strjoin(main_line, "\n");
		printf("%s\n%s", ":-) got one line of tetromino", main_line);
		counter--;
	}
	if (counter < 4)
	{
		free(tmp_line);
		return (*new_element);
	}
	new_element->content = ft_strdup(main_line);
	return (*new_element);
}

t_list	*get_tetriminos(int fd)
{
	t_list	*tmp_list;
	t_list	*head;

	tmp_list = ft_lstnew("\0", 0);
	head = tmp_list;
	*tmp_list = get_one_tetrimino(tmp_list, fd);
	printf("%s\n", ":-) got one tetromino");
	return (tmp_list);
}
