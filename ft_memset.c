/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:22:48 by hbui              #+#    #+#             */
/*   Updated: 2021/11/22 15:38:45 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	char			*str;
	int				i;

	if (len <= 0)
		return (b);
	ch = c;
	i = 0;
	str = (char *) b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
