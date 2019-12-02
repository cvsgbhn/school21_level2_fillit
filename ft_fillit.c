# include "libft/libft.h"
# include "libft/get_next_line.h"

int     check_tetrimino_line(char *line, int decounter)
{
    int     counter;
    size_t  length;

    counter = 0;
    length = ft_strlen(line);
    // check length (4 + '\n')
    // check if there are only '*' and '#'
    if (decounter == 1 && length == 1 && line == "\n")
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
    return (1)
}

// TODO: add to libft
int     count_symbol(char *line, char symbol)
{
// count symbol appearance in line
    int     counter;

    counter = 0;
    while (line)
    {
        if (line == symbol)
            counter++;
        line++;
    }
    return (counter);
}

//read given file, creating new list element for a single tetromino
t_list  *read_single_tetrimino(int fd)
{
    t_list  *tetrimino_block;
    char    *temp_line;
    char    *tetrimino_line;
    int     decounter;

    decounter = 5;
    temp_line = NULL;
    tetrimino_block = NULL;
    while (decounter > 0)
    {
        // TODO: add check on gnl
        get_next_line(fd, temp_line);
        if (check_tetrimino_line(temp_line, decounter) == -1)
            return (NULL);
        if (check_tetrimino_line(temp_line, decounter) == 0)
            break ;
        tetrimino_line = ft_strjoin(tetrimino_line, temp_line);
        free(temp_line);
        decounter--;
    }

    // set a loop, sum the '#' for every 4 valid lines
    // when 4 in a row are valid - create t_list element and copy from line to t_list->content
    // free line and set hash-counter = 0
    return (tetrimino_block);
}

// TODO: create func that apply exact letter to exact number of tetrimino

int     main(int argc, char **argv)
{
    int     count;


    fd = open(argv[1], O_RDONLY);
    while (get_tetrominos(fd))
    {

    }

    return (1);
}
