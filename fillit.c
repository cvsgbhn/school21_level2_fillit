# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "fillit.h"

int count_not_symbol(char symb, char *str)
{
	int iterator = 0;
	int counter = 0;

	while (str[iterator])
	{
		if (str[iterator] != '.')
			counter++;
	}
	return (counter);
}

int check_one_tetromino(d_list tetromino)
{
    int     validator;
    int     counter;

    validator = 0;
    counter = 0;
	if ((count_not_symbol('.', tetromino->content)) == 4)
	{
	    while (tetromino)
	}
}

int	check_one_tetrostring(char *string)
{
	int iterator;

	iterator = 0;
	if ft_strlen(string) != 5
		return (0);
	while (string[iterator] != '\n')
	{
		if (string[iterator] != '.' && string[iterator] != '#')
			return (0);
	}
	return (1);
}

/*
 * this function replaces one given character (original) to another given character (new) in a given string (string)
 */
char* replace_character(char *string, char original, char new)
{
    char    *new_string;
    int     counter;

    new_string = ft_memalloc(ft_strlen(string));
    counter = 0;
    while (string[counter])
    {
        if (string[counter] == original)
            new_string[counter] = new;
        else
            new_string[counter] = string[counter];
        counter++;
    }

    return (new_string);
}

/*
 * here we read and write just one tetromino to its own element of DDL
 */
int	get_one_tetrimino(d_list **new_element, int fd, size_t letter)
{
	char	*tmp_line;
	char 	*main_line;
	int 	counter;

	main_line = "";
	counter = 0;
	// single tetromino string has 4 newlines
	while (counter <= 4)
	{
		if(!(get_next_line(fd, &tmp_line)))
		// TODO: checking function, smth like: checking_function(char *tmp_line, ....)
			break ;
		check_one_tetrostring(tmp_line);
		main_line = ft_strjoin(main_line, tmp_line);
		main_line = ft_strjoin(main_line, "\n");
		counter++;
	}
	if (counter < 4)
		return (0);
    (*new_element)->content = ft_strdup(main_line);
    (*new_element)->content_size = letter;
	return (1);
}

/*
 * this funciton takes existing DDL and adds to it one by one new elements with written tetrominoes
 */
d_list	*get_tetriminos(int fd)
{
	d_list	*tmp_list;
	d_list  *next_list;
	d_list	*head;
	size_t  letter_num;

	letter_num = 65;
	tmp_list = ft_doubly_linked_lstnew("\0", 0);
	head = tmp_list;
	while ((get_one_tetrimino(&tmp_list, fd, letter_num)))
    {
	    next_list = ft_doubly_linked_lstnew("\0", 0);
	    ft_doubly_linked_lstadd_toend(&tmp_list, next_list);
	    tmp_list->content = replace_character(tmp_list->content, '#', letter_num);
	    tmp_list = tmp_list->next;
	    letter_num ++;
    }
	// test printf, never mind
	printf("%s\n", ":-) got one tetromino");


	return (head);
}
