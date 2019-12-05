# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "fillit.h"

/*int     check_tetrimino_line(char *line, int decounter)
{
    int     counter;
    size_t  length;

    counter = 0;
    length = ft_strlen(line);
    // check length (4 + '\n')
    // check if there are only '*' and '#'
    printf("%s", line);
    if (decounter == 1 && length == 1 && ft_strcmp(line, "\n") == 1)
        return (0);
    // 0 - it's pause line, ok, just skip it
    if (length != 4)
        return (-1);
   // -1 means error
    while (line[counter])
    {
        if (line[counter] != '*' && line[counter] != '#')
            return (-1);
    }
    return (1);
}

// TODO: add to libft
int     count_symbol(char *line, char symbol)
{
// count symbol appearance in line
    int     counter;
    int 	index;

    counter = 0;
    index = 0;
    while (line[index])
    {
        if (line[index] == symbol)
            counter++;
        index++;
    }
    return (counter);
}

//read given file, creating new list element for a single tetromino
t_list  *read_single_tetrimino(int fd, t_list **input)
{
    //t_list  *tetrimino_block;
    char    *temp_line;
    char    *tetrimino_line;
    int     decounter;
    int 	hash_counter;
    int a;
    t_list  *tetrimino_block;


    if (input)
    	ft_putchar('Q');
    decounter = 5;
    hash_counter = 0;
    temp_line = NULL;
    tetrimino_block = ft_lstnew("\0", 1);
    while (decounter > 0 && (a = get_next_line(fd, &temp_line)) > 0)
    {
    	if (check_tetrimino_line(temp_line, decounter) == -1)
    		return (tetrimino_block);
    	if (check_tetrimino_line(temp_line, decounter) == 0)
			break;
		tetrimino_line = ft_strjoin(tetrimino_line, temp_line);
		free(temp_line);
		decounter--;
    }
	  hash_counter = hash_counter + count_symbol(tetrimino_line, '#');
    if (hash_counter != 4)
      return (tetrimino_block);
    if (a == 0)
      return (tetrimino_block);
    // set a loop, sum the '#' for every 4 valid lines
    // when 4 in a row are valid - create t_list element and copy from line to t_list->content
    // free line and set hash-counter = 0
    return (tetrimino_block);
}

t_list *get_tetriminos(int fd)
{
  t_list  *return_list;
  t_list  *temp_list;

  return_list = ft_lstnew("\0", fd);
  temp_list = return_list;
  return_list = read_single_tetrimino(fd, &temp_list);

  //while (return_list = read_single_tetrimino(fd, &return_list))
  return (return_list);
}*/
// TODO: create func that apply exact letter to exact number of tetrimino

t_list	*get_tetriminos(int fd, t_list *input)
{
	printf("%s", "inside get_tetriminos - 0");
	//t_list	*tmp_list;
	char 	*tmp_str;
	char	*another_str;
	int		decounter;

	//tmp_list = input;
	another_str = NULL;
	decounter = 4;
	printf("%s", "inside get_tetriminos - 0");
	while (decounter > 0)
	{
		get_next_line(fd, &tmp_str);
		another_str = ft_strjoin(tmp_str, "\n");
		printf("%s", another_str);
		//input->content = ft_strjoin(another_str, tmp_str);
		decounter--;
	}
	return (input);
}