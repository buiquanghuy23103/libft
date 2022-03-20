/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 08:27:11 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 11:03:29 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	base_len(unsigned long long num, const unsigned int base)
{
	int	len;

	len = 1;
	while (num / base != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

void	build_unum(t_format *fm, unsigned long long num,
	const unsigned int base)
{
	int		len;
	char	*str;

	len = base_len(num, base);
	str = "0123456789abcdef";
	fm->main = ft_strnew(len);
	fm->main[0] = '0';
	while (--len > -1)
	{
		fm->main[len] = str[num % base];
		num /= base;
	}
}

void	build_num(t_format *fm, long long num, const unsigned int base)
{
	unsigned long long	unum;

	fm->neg = num < 0;
	if (fm->neg)
		unum = (unsigned long long)(-1 * (num + 1)) + 1;
	else
		unum = (unsigned long long)num;
	build_unum(fm, unum, base);
}
