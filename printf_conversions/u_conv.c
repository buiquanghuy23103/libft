/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:56:26 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 10:30:15 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_main(t_format *fm)
{
	if (ft_strequ(fm->mod, "l"))
		build_unum(fm, va_arg(fm->ap, unsigned long), 10);
	else if (ft_strequ(fm->mod, "ll"))
		build_unum(fm, va_arg(fm->ap, unsigned long long), 10);
	else if (ft_strequ(fm->mod, "hh"))
		build_unum(fm, (unsigned char)va_arg(fm->ap, unsigned int), 10);
	else
		build_unum(fm, va_arg(fm->ap, unsigned int), 10);
}

static void	build_prefix(t_format *fm)
{
	int	size;

	size = fm->prec - ft_strlen(fm->main);
	if (size <= 0)
		return ;
	fm->prefix = ft_strnew(size);
	ft_memset(fm->prefix, '0', size);
}

void	u_conv(t_format *fm)
{
	build_main(fm);
	if (fm->prec == 0 && fm->main[0] == '0')
		fm->main[0] = '\0';
	build_prefix(fm);
}
