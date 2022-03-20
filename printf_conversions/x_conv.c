/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:03:48 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 10:30:28 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_main(t_format *fm)
{
	if (ft_strequ(fm->mod, "l"))
		build_unum(fm, va_arg(fm->ap, unsigned long), 16);
	else if (ft_strequ(fm->mod, "ll"))
		build_unum(fm, va_arg(fm->ap, unsigned long long), 16);
	else if (ft_strequ(fm->mod, "hh"))
		build_unum(fm, (unsigned char)va_arg(fm->ap, unsigned int), 16);
	else
		build_unum(fm, va_arg(fm->ap, unsigned int), 16);
}

static void	build_prefix(t_format *fm)
{
	int		size;
	char	*temp;

	size = fm->prec - ft_strlen(fm->main);
	if (size > 0)
	{
		fm->prefix = ft_strnew(size);
		ft_memset(fm->prefix, '0', size);
	}
	else
		fm->prefix = ft_strnew(2);
	if (ft_strchr(fm->flags, '#') && fm->main[0] != '0' && fm->prec != 0)
	{
		temp = fm->prefix;
		fm->prefix = ft_strjoin("0x", fm->prefix);
		ft_strdel(&temp);
	}
}

void	x_conv(t_format *fm)
{
	build_main(fm);
	if (fm->prec == 0 && fm->main[0] == '0')
		fm->main[0] = '\0';
	build_prefix(fm);
}
