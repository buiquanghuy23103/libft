/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:18:29 by hbui              #+#    #+#             */
/*   Updated: 2022/03/03 21:32:06 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_main(t_format *fm)
{
	if (ft_strequ(fm->mod, "l"))
		build_num(fm, va_arg(fm->ap, long), 10);
	else if (ft_strequ(fm->mod, "ll"))
		build_num(fm, va_arg(fm->ap, long long), 10);
	else if (ft_strequ(fm->mod, "h"))
		build_num(fm, (short)va_arg(fm->ap, int), 10);
	else if (ft_strequ(fm->mod, "hh"))
		build_num(fm, (signed char)va_arg(fm->ap, int), 10);
	else
		build_num(fm, va_arg(fm->ap, int), 10);
}

static void	build_prefix(t_format *fm)
{
	int	size;

	size = fm->prec - ft_strlen(fm->main) + 1;
	if (size < 1)
		size = 1;
	fm->prefix = ft_strnew(size);
	ft_memset(fm->prefix, '0', size);
	if (fm->neg)
		fm->prefix[0] = '-';
	else if (ft_strchr(fm->flags, '+'))
		fm->prefix[0] = '+';
	else if (ft_strchr(fm->flags, ' '))
		fm->prefix[0] = ' ';
	else
		fm->prefix[size - 1] = '\0';
}

void	d_conv(t_format *fm)
{
	build_main(fm);
	if (fm->prec == 0 && fm->main[0] == '0')
		fm->main[0] = '\0';
	build_prefix(fm);
}
