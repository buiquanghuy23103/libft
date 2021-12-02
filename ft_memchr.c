/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:02:03 by hbui              #+#    #+#             */
/*   Updated: 2021/12/02 08:50:11 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str_s;
	unsigned char	unsigned_c;

	i = 0;
	str_s = (unsigned char *) s;
	unsigned_c = (unsigned char) c;
	while (i < n)
	{
		if (str_s[i] == unsigned_c)
			return (str_s + i);
		i++;
	}
	return (NULL);
}
