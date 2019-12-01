# include "libft/libft.h"
# include "libft/get_next_line.h"

int     check_tetrimino_line(char *line)
{
    int     counter;
    size_t  length;

    counter = 0;
    length = ft_strlen(line);
    //check length (4 + '\n')
    //check if there are only '*' and '#'
    if (length == 1)
        return (0);
    else if (length != 4)
        return (-1);
    // 0 means need extra check if it's empty line between 2 tetrimino blocks
   //  -1 means error
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
t_list  read_single_tetrimino(fd)
{
    t_list  *tetrimino_block;
    char    *temp_line;
    char    *tetrimino_line;

    temp_line = NULL;
    tetrimino_block = NULL;
    while (get_next_line(fd, tetrimino_line))
    {
        if (check_tetrimino_line(tetrimino_line) == -1)
            return (-1);
        else if (check_tetrimino_line(tetrimino_line) == 0)
            check_break_line(tetrimino_line);
    }

    // check_tetrimino_line
    // if !tetromino -> check for empty line
    // if line is valid - count_symbols(line)
    // set a loop, sum the '#' for every 4 valid lines
    // when 4 in a row are valid - create t_list element and copy from line to t_list->content
    // free line and set hash-counter = 0
    return (tetrimino_block);
}

// TODO: create func that apply exact letter to exact number of tetrimino
// check_break_line(char *line)

int     main(int argc, char **argv)
{
    fd = open(argv[1], O_RDONLY);

    return (1);
}
