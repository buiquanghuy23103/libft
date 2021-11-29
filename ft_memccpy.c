/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:26:15 by hbui              #+#    #+#             */
/*   Updated: 2021/11/29 22:15:12 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*str_src;
	size_t		i;

	str_src = (const char *) src;
	i = 0;
	while (str_src[i] && i < n && str_src[i] != c)
		i++;
	if (str_src[i] == c)
	{
		i++;
		ft_memcpy(dst, src, i);
		return (dst + i);
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
