/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:35:21 by hbui              #+#    #+#             */
/*   Updated: 2022/04/01 15:17:57 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	temp = NULL;
	while (lst)
	{
		if (!new_lst)
		{
			new_lst = f(lst);
			temp = new_lst;
		}
		else
		{
			temp->next = f(lst);
			if (!temp->next)
				return (new_lst);
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (new_lst);
}
