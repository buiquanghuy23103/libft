/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:22:53 by hbui              #+#    #+#             */
/*   Updated: 2022/03/31 22:41:47 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_pop_front(t_list **lst)
{
	t_list	*ret;

	if (!lst || !*lst)
		return (NULL);
	ret = *lst;
	*lst = ret->next;
	ret->next = NULL;
	return (ret);
}
