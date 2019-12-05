# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "fillit.h"

t_list	*get_tetriminos(int fd, t_list **input)
{
	printf("%s\n", "inside get_tetriminos - 0");
	t_list	*tmp_list;
	char 	*tmp_str;
	char	*another_str;
	int		decounter;

	tmp_list = *input;
	decounter = 4;
	another_str = "";

	printf("%s\n", "inside get_tetriminos - 1");
	while (get_next_line(fd, &tmp_str))
	{
		if (decounter == -1)
		{
			decounter = 4;
			tmp_list = ft_lstnew("\0", 0);
		}
		// get_next_line(fd, &tmp_str);
		// TODO: @celeanor, here should be be your checking funciton
		// aka: if (!(the_checking_function(tmp_str))
		//		return (NULL);
		another_str = ft_strjoin(another_str, tmp_str);
		//printf("%s\n", another_str);
		another_str = ft_strjoin(another_str, "\n");
		decounter--;
		tmp_list->content = another_str;
		ft_lstadd_toend(&tmp_list, tmp_list -> next);
	}
	return (tmp_list);
}
