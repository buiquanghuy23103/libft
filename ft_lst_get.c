/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:29:10 by hbui              #+#    #+#             */
/*   Updated: 2022/03/30 22:41:12 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Get by index
** Negative index start at the end.
** e.g.  0 : first elem
**      -1 : last elem
*/

t_list	*ft_lst_get(t_list *lst, int index)
{
	int	i;

	if (index < 0)
		index = ft_lst_len(lst) + index;
	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst);
		i++;
		lst = lst->next;
	}
	return (lst);
}
