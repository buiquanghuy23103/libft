/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:14:31 by hbui              #+#    #+#             */
/*   Updated: 2022/04/01 09:37:20 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_pop_back(t_list **lst)
{
	t_list	*ptr;

	if (!lst || !*lst)
		return (NULL);
	ptr = ft_lst_get(*lst, -1);
	if (ft_lst_len(*lst) == 1)
		*lst = NULL;
	else
		ft_lst_get(*lst, -2)->next = NULL;
	return (ptr);
}
