/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:18:05 by hbui              #+#    #+#             */
/*   Updated: 2021/12/02 22:02:08 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	i;
	int	dst_strlen;
	int	src_strlen;

	i = 0;
	dst_strlen = ft_strlen(dst);
	src_strlen = ft_strlen(src);
	if (dstsize > dst_strlen)
	{
		while (i < dstsize - dst_strlen - 1 && src[i])
		{
			dst[dst_strlen + i] = src[i];
			i++;
		}
		dst[dst_strlen + i] = '\0';
		return (dst_strlen + src_strlen);
	}
	return (dstsize + src_strlen);
}
