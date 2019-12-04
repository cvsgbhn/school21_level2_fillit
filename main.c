# include "fillit.h"

void print_linked_list(t_list the_list)
{
	while (the_list->next)
	{
		ft_putstr(the_list->content);
		the_list = the_list->next;
	}
	ft_putstr(the_list->content);
	ft_putchar('\n');
}

int     main(int argc, char **argv)
{
	int		count;
	char	*result;
	t_list *input_data;

	fd = open(argv[1], O_RDONLY);
	if(!(get_tetriminos(input_data))
		return (-1);
	// solve_task - solves tetromino puzzle
	if (solve_task(input_data, result))
	{
			//solution stuff
	}
	print_linked_list(&input_data);
	// TODO: add print list function
	return (1);

}
