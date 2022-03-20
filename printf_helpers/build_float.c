/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:24:31 by hbui              #+#    #+#             */
/*   Updated: 2022/03/07 12:59:19 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	round(long double num, int precision)
{
	long double	extra;

	extra = 0.5;
	if (precision <= 0)
		return (num);
	while (precision--)
		extra /= 10;
	return (num + extra);
}

static void	build_fractional_part(t_format *fm, long double after_dot)
{
	char			*str;
	char			*temp;
	unsigned int	i;

	if (fm->prec < 0)
		fm->prec = 6;
	if (!fm->prec)
		return ;
	i = fm->prec + 1;
	str = ft_strnew(fm->prec + 1);
	str[0] = '.';
	after_dot = round(after_dot, fm->prec);
	while (--i > 0)
	{
		after_dot *= 10.0;
		str[fm->prec + 1 - i] = (int)(after_dot) + '0';
		after_dot -= (int)(after_dot);
	}
	temp = fm->main;
	fm->main = ft_strjoin(fm->main, str);
	ft_strdel(&temp);
	ft_strdel(&str);
}

void	build_float(t_format *fm, long double num)
{
	long		before_dot;
	long double	after_dot;
	int			temp;

	temp = (num < 0.0L || num == -0.0L);
	before_dot = (long)num;
	after_dot = num - (long double)before_dot;
	if (after_dot < 0)
		after_dot *= -1;
	build_num(fm, before_dot, 10);
	build_fractional_part(fm, after_dot);
	fm->neg = temp;
}
