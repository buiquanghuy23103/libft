/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:42:18 by hbui              #+#    #+#             */
/*   Updated: 2021/12/07 10:06:25 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*u1;
	unsigned char	*u2;

	i = 0;
	if (n == 0)
		return (0);
	u1 = (unsigned char *) s1;
	u2 = (unsigned char *) s2;
	while (i < n - 1 && u1[i] && u2[i] && u1[i] == u2[i])
	{
		i++;
	}
	return (u1[i] - u2[i]);
}
