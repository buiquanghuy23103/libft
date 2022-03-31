/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:45:39 by hbui              #+#    #+#             */
/*   Updated: 2022/03/31 23:12:24 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_push_front(t_list **lst, void *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(content, content_size);
	if (!lst || !new_elem)
		return (NULL);
	if (!*lst)
		*lst = new_elem;
	else
	{
		new_elem->next = *lst;
		*lst = new_elem;
	}
	return (*lst);
}
