/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:32:05 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 10:27:37 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_main(t_format *fm)
{
	if (ft_strequ(fm->mod, "l"))
		build_unum(fm, va_arg(fm->ap, unsigned long), 2);
	else if (ft_strequ(fm->mod, "ll"))
		build_unum(fm, va_arg(fm->ap, unsigned long long), 2);
	else if (ft_strequ(fm->mod, "hh"))
		build_unum(fm, (unsigned char)va_arg(fm->ap, unsigned int), 2);
	else
		build_unum(fm, va_arg(fm->ap, unsigned int), 2);
}

static void	build_prefix(t_format *fm)
{
	int	size;

	size = fm->prec - ft_strlen(fm->main) + 2;
	if (size > 2)
	{
		fm->prefix = ft_strnew(size);
		ft_memset(fm->prefix, '0', size);
	}
	else
		fm->prefix = ft_strnew(2);
	if (ft_strchr(fm->flags, '#') && fm->main[0] != '0' && fm->prec != 0)
		ft_strcpy(fm->prefix, "0b");
}

void	b_conv(t_format *fm)
{
	build_main(fm);
	if (fm->prec == 0 && fm->main[0] == '0')
		fm->main[0] = '\0';
	build_prefix(fm);
}
