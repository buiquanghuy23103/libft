/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:41:34 by hbui              #+#    #+#             */
/*   Updated: 2022/03/23 07:14:41 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_push_back(t_list **lst, void *content, size_t content_size)
{
	t_list	*temp;

	if (!*lst)
		*lst = ft_lstnew(content, content_size);
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_lstnew(content, content_size);
	}
	return (*lst);
}
