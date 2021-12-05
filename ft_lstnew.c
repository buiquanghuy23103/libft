/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:03:28 by hbui              #+#    #+#             */
/*   Updated: 2021/12/05 11:03:55 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list)
	{
		list->next = NULL;
		list->content = (void *)content;
		if (!content)
			list->content_size = 0;
		else
			list->content_size = content_size;
		return (list);
	}
	return (NULL);
}
