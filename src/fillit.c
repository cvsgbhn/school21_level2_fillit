# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "fillit.h"

/*
 * transformation from Knuth's matrix to char[][]
 */
void	transformate(x_node *result, char **matrix)
{
    // 0. fill matrix with '.'
	// 1. take node's coords and letter
	// 2. put chars in matrix according 1
	// 3. repeat while result
	int     num;
  x_node  *x_down;
  x_node *x_right;
  col_obj *fix_col;

	num = -1;
  x_down = result;
  while ((x_down->down) != result)
  {
    x_right = x_down;
	   while (num++ < 4)
     {
	       fix_col = (x_right->C);
	       matrix[(fix_col->x)][fix_col->y] = (x_down->letter) + '0';
	       x_right = x_right->right;
     }
     x_down = x_down->down;
   }
}
/*
 * printing result matrix
 */
void	print_result(x_node *result, int size)
{
	char	*matrix;
	int 	row;
	int 	col;

	row = 0;
	matrix = (char *)malloc(size * size * sizeof(char));
	transformate(result, &matrix);
	while(row++ <= size)
	{
		col = 0;
		while(col++ <= size)
			ft_putstr(&(matrix[col]));
		matrix++;
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
	printf("%s\n", "fillit.c/main input_data :77");
	size = find_field_size(dl_length(input_data));
    printf("%s\n", "fillit.c/main find_field_size :78");
	initial_matrix = create_xnode_list(size, 65);
	create_headers_list(initial_matrix, size);
	add_all_tetromino_positions(input_data, initial_matrix, size);
	while ((search(initial_matrix, result, 0, initial_matrix->letter)) == 0)
	{
		size++;
		initial_matrix = create_xnode_list(size, 65);
		create_headers_list(initial_matrix, size);
		add_all_tetromino_positions(input_data, initial_matrix, size);
	}
	print_result(initial_matrix, size);
	return (1);
}
