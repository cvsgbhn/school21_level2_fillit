# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "fillit.h"

/*
 * function to print doubly linked list (let it be - DDL)
 * need it to test if I collect tetrominos correct
 */
void print_doubly_linked_list(d_list *head) {
    d_list *current_node;

    current_node = head;
    while ( current_node != NULL) {
        /*
         * extra printf "one node" to check that in every element of DDL I have only ONE tetromino
         */
        printf("%s\n", "one node");
        printf("%s ", current_node->content);
        current_node = current_node->next;
    }
}


/*
 * main function, where it all starts

int     main(int argc, char **argv)
{
    // create empty DDL to write input there
	d_list *input_data;
	// GNL needs fd, remember?
	int fd;

	// check if we have any file on the input as command line argument
	if (argc < 2)
	    // if no arguments - exit with -1
		return (-1);

	// read the file
	fd = open(argv[1], O_RDONLY);
	// write to the input_data terominoes
	input_data = get_tetrominos(fd);
	// print our DDL, just to check if everything is alright
	print_doubly_linked_list(input_data);
	// if success - return 1
	return (1);

}
*/

/*
 * transformation from Knuth's matrix to char[][]
 */
void	transformate(x_node *result, char **matrix[size][size])
{
    // 0. fill matrix with '.'
	// 1. take node's coords and letter
	// 2. put chars in matrix according 1
	// 3. repeat while result
	int     num;
	int     pair[2];

	num = -1;
	while (num++ < 4)
    {
	    pair[0] = result->C->x_coords[num];
	    pair[1] = result->C->y_coords[num];
	    matrix[pair[0]][pair[1]] = (result->letter) + '0';
    }
}

/*
 * printing result matrix
 */
void	print_result(x_node *result, int size)
{
	char	matrix[size + 1][size + 1];
	int 	row;
	int 	col;

	row = 0;
	transformate(&result, &matrix);
	while(row++ <= size)
	{
		col = 0;
		while(col++ <= size)
			ft_putstr(matrix[row, col]);
	}


}
/*
 * new main funciton
*/
int main(int argc, char **argv)
{
	// create empty DDL to write input there
	d_list *input_data;
	// GNL needs fd, remember?
	int fd;
	int size;
	x_node *result;
	x_node *initial_matrix;
	// check if we have any file on the input as command line argument
	if (argc < 2)
	    // if no arguments - exit with -1
		return (-1);

	// read the file
	result = NULL;
	fd = open(argv[1], O_RDONLY);
	// write to the input_data terominoes
	input_data = get_tetrominos(fd);
	size = find_field_size(dl_length(&input_data));
	initial_matrix = create_xnode_list(size, 65);
	create_headers_list(initial_matrix, size);
	add_all_tetromino_positions(&input_data, &initial_matrix);
	while ((search(initial_matrix, result, 0, initial_matrix->content_size)) == 0)
	{
		size++;
		initial_matrix = create_xnode_list(size, 65);
		create_headers_list(initial_matrix, size);
		add_all_tetromino_positions(&input_data, &initial_matrix);
	}
	print_result(&initial_matrix);
	return (1);
}
