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

	if (argc < 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	printf ("%d", fd);
	input_data = NULL;
	printf ("%s", "ok, i am here - 0");
	get_tetriminos(fd, input_data);
	/*if(!(get_tetriminos(input_data)))
		return (-1);
	// solve_task - solves tetromino puzzle
	 if (solve_task(input_data, result))
	{
			//solution stuff
	} */
	print_linked_list(input_data);
	printf ("%s", "ok, i am here");
	// TODO: add print list function
	return (1);

}
