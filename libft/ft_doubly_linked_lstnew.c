/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdanilo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:03:02 by vdanilo           #+#    #+#             */
/*   Updated: 2019/11/21 21:02:49 by vdanilo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

d_list	*ft_doubly_linked_lstnew(void const *content, size_t content_size)
{
	d_list	*newlist;
	size_t	copy_size;

	copy_size = content_size;
	newlist = (d_list*)malloc(sizeof(struct s2_list));
	if (!newlist)
	{
		free(newlist);
		return (NULL);
	}
	if (!content)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		newlist->content = ft_strdup((void*)content);
		newlist->content_size = copy_size;
	}
	newlist->next = NULL;
	newlist->previous = NULL;
	newlist->x_coords = [0, 0, 0, 0];
	newlist->y_coords = [0, 0, 0, 0];
	return (newlist);
}
