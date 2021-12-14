/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:35:21 by hbui              #+#    #+#             */
/*   Updated: 2021/12/14 10:58:00 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*temp;

	if (lst && f)
	{
		new_lst = f(lst);
		if (new_lst)
		{
			temp = new_lst;
			lst = lst->next;
			while (lst)
			{
				temp->next = f(lst);
				temp = temp->next;
				if (temp)
					temp->next = NULL;
				else
				{
					ft_lstdel(new_lst);
					return (NULL);
				}
				lst = lst->next;
			}
		}
		return (new_lst);
	}
	return (NULL);
}
