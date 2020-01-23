# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "fillit.h"

void    *coords_rollback(int last_coord, d_list tetrimino)
{
    // coords - 1
    int     counter;

    counter = 0;
    while (counter != last_coord)
    {
        tetrimino.coords[counter]--;
        counter++;
    }
}

void    *move_tetrimino_once(int square_size, d_list tetrimino)
{
    int     iterator;

    iterator = 0;
  // 1. x coord ++
  while ((tetrimino.coords)[iterator] < 8)
  {
      tetrimino.coords[iterator]++;
      if (tetrimino.coords[iterator] > square_size)
      {
          coords_rollback(iterator, &tetrimino);



      }
      // 2. if x coord > square_size => x coord = 0, y coord ++
      // 3. if y coord > square_size => end
      iterator = iterator + 2;
  }

}

int     *find_old_coordinates(char *tetrimino)
{
    int     rows_num;
    int     counter;
    int     coordinates[8];
    int     coord;

    rows_num = 0;
    counter = 0;
    coord = 0;
    while (rows_num != 3)
    {
        while (tetrimino[counter + 4*rows_num] && counter != 4)
        {
            if (tetrimino[counter + 4*rows_num] == '#')
            {
                coordinates[coord] = counter;
                coordinates[coord + 1] = rows_num;
                coord += 2;
            }
            counter ++;
        }
        rows_num++;
    }
    return (coordinates);
}

int   *parse_to_xy(int coords[8], char xory)
{
  int   iterator;
  int   subcoor;
  int   oxoy[4];

  iterator = 0;
  subcoor = 0;
  oxoy = [0,0,0,0];
  if (xory == 'y')
    iterator++;
  while (iterator < 8)
  {
    oxoy[subcoor] = coords[iterator];
    subcoor++;
    iterator += 2;
  }
  return (oxoy);
}

int     min_in_array(int *numbers)
{
    int     min;
    int     counter;

    counter = 0;
    min = numbers[counter];
    while (numbers[counter])
    {
        if (numbers[counter] < min)
            min = numbers[counter];
        counter++;
    }
    return (min);
}

int     *find_new_coordinates(char *tetrimino)
{
    int     coords_x[4];
    int     coords_y[4];
    int     counter;
    int     x;
    int     y;

    counter = 0;
    coords = find_old_coordinates(tetrimino);
    x = 0;
    y = 0;
    while (counter != 8)
    {
        if (counter == 0 || counter % 2 == 0)
        {
            coords_x[x] = coords[counter];
            x++;
        }
        else
        {
            coords_y[y] = coords[counter];
            y++;
        }
        counter++;
    }
    min_x = min_in_array(coords_x);
    min_y = min_in_array(coords_y)
    while (counter != 0)
    {
        if (counter == 0 || counter % 2 == 0)
            coords[counter] == coords[counter] - min_y;
        else
            coords[counter] == coords[counter] - min_x;
        counter++;
    }
    return (coords);
}

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

//////////////////////////////////////////////////
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
//////////////////////////////////////////////////

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
    (*new_element)->x_coords[0,0,0,0];
    (*new_element)->y_coords[0,0,0,0];
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
