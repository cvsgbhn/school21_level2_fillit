# include "fillit.h"
/*
 * there are some additional info in README
 */


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
 */
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
	input_data = get_tetriminos(fd);
	// print our DDL, just to check if everything is alright
	print_doubly_linked_list(input_data);
	// if success - return 1
	return (1);

}
