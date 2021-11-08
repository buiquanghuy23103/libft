/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:35:17 by hbui              #+#    #+#             */
/*   Updated: 2021/11/08 22:05:16 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		isNegative;
	int		i;
	int		numlen;

	isNegative = n < 0;
	numlen = ft_numlen(n);
	str = (char *)malloc((numlen + isNegative + 1) * sizeof(char));
	if (!str)
		return NULL;
	i = numlen + isNegative;
	str[i] = '\0';
	i--;
	while (i >= isNegative)
	{
		str[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i--;
	}
	if (isNegative)
		str[0] = '-';
	return (str);
}
