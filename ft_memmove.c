/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:01:42 by hbui              #+#    #+#             */
/*   Updated: 2021/12/01 17:23:43 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*str_dst;
	char	*dup;

	i = 0;
	str_dst = (char *) dst;
	dup = ft_strdup((char *) src);
	while (i < len)
	{
		str_dst[i] = dup[i];
		i++;
	}
	free(dup);
	return (dst);
}
