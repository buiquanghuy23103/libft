/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:26:15 by hbui              #+#    #+#             */
/*   Updated: 2021/12/06 22:46:07 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*str_src;
	unsigned char		ch;
	size_t				i;

	str_src = (const unsigned char *) src;
	ch = (unsigned char) c;
	i = 0;
	while (str_src[i] && i < n && str_src[i] != ch)
		i++;
	if (str_src[i] == ch)
	{
		i++;
		ft_memcpy(dst, src, i);
		return (dst + i);
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}

// void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
// 		if (((const unsigned char *)src)[i] == (unsigned char)c)
// 			return ((unsigned char *)dst + i + 1);
// 		i++;
// 	}
// 	return (0);
// }