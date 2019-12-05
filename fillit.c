# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "fillit.h"

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
