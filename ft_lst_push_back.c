/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:41:34 by hbui              #+#    #+#             */
/*   Updated: 2022/03/22 22:18:15 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_push_back(t_list *lst, void *content, size_t content_size)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	lst->next = ft_lstnew(content, content_size);
	return (lst);
}