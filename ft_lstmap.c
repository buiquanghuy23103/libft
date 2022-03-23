/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:35:21 by hbui              #+#    #+#             */
/*   Updated: 2022/03/23 07:15:59 by hbui             ###   ########.fr       */
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
	while (lst)
	{
		temp = f(lst);
		ft_lst_push_back(&new_lst, temp->content, temp->content_size);
		lst = lst->next;
	}
	return (new_lst);
}
