#include "dlx_algorithm.h"

/*
* almost the same like move tetromino further - rollback.
* but only for x axys.
* may be there will be one for y rollback, i have no fucking idea
*/
// ACHTUNG! WORK IS CONTINUING
void    *coords_rollback(int last_coord, d_list tetromino)
{
    int     counter;

    counter = -1;
    while (counter++ <= last_coord)
        tetromino.coords[counter]--;
}

/*
* move tetrimino figure on the board, one position further to the right.
* we need here to recalculate coordinates for every spot.
* if any single spot coordinate > size of board: rollback,
* move further down the board.
* if the end of board reached - return something like nothing
*/
void    *move_tetromino_once(int square_size, int x_coords[4], int y_coords[4])
{
    int     ox;
    int     oy;

    ox = -1;
    oy = -1;
    while (ox++ < 4)
    {
      if (x_coords[ox] > square_size)
      {
        coords_rollback(ox, x_coords);
        while (oy++ < 4)
        {
          y_coords[oy]++;
          if (y_coords[oy] >square_size)
          {
            coords_rollback(oy, y_coords);
            ox = 4;
            oy = 4;
          }
        }
      }
      x_coords[ox]++;
    }
  }
}

/*
* write original coordinates of every point of tetromino
* in a single array
*/
int     *find_old_coordinates(char *tetromino)
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
        while (tetromino[counter + 4*rows_num] && counter != 4)
        {
            if (tetromino[counter + 4*rows_num] == '#')
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

/*
* function to separate unioned coordinates to x-coordinates array
* and y-coordinates array
*/
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

/*
* function to find minimum int in the int* array
*/
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

/*
* moving tetromino to (0;0) spot on the field
* for every x in x-coordinates array: x = x - min(x-coordinates)
* for every y in y-coordinates array: y = y - min(y-coordinates)
*/
int   *find_new_coordinates(int *xory_coords)
{
  int   counter;
  int   min;

  counter = 0;
  min = min_in_array(xory_coords);
  while (counter < 4)
  {
    xory_coords[counter] = xory_coords[counter] - min;
    counter++;
  }
  return (xory_coords);
}

/*
* function to check symbol validity
*/
// TODO: wtf is this???? I need normal one!!!!!!!
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


/*
* check validity of the one string of tetromino
*/
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
 * here we read and write just one tetromino to its own element of DDL
 */
int	get_one_tetromino(d_list **new_element, int fd, size_t letter)
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
