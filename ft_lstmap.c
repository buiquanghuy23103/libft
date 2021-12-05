/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:35:21 by hbui              #+#    #+#             */
/*   Updated: 2021/12/05 13:07:38 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if (lst)
	{
		new_lst = (t_list *)ft_memalloc(sizeof(t_list));
		if (new_lst)
		{
			while (lst->next)
			{
				f(lst)->next = f(lst->next);
				lst = lst->next;
			}
		}
		return (new_lst);
	}
	return (NULL);
}
