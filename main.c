# include "fillit.h"

void print_linked_list(t_list *head) {
	t_list *current_node;

	current_node = head;
	while ( current_node != NULL) {
		printf("%s ", current_node->content);
		current_node = current_node->next;
	}
}

int     main(int argc, char **argv)
{
	t_list *input_data;
	int fd;
	char *line;

	if (argc < 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n%s\n%s", "AAAAAAAAAA", line, "AAAAAAAAAA");
	printf ("%d\n", fd);
	input_data = ft_lstnew("whatever message", 0);
	print_linked_list(input_data);
	printf ("%s\n", "ok, i am here - 0");
	input_data = get_tetriminos(fd);
	/*if(!(get_tetriminos(input_data)))
		return (-1);
	// solve_task - solves tetromino puzzle
	 if (solve_task(input_data, result))
	{
			//solution stuff
	} */
	print_linked_list(input_data);
	//input_data = input_data->next;
	printf("%s\n", "attention! new print");
	printf("%s ", input_data->content);
	printf ("%s\n", "ok, i am here");
	// TODO: add print list function
	return (1);

}
