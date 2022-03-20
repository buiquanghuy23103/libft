/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:54:59 by hbui              #+#    #+#             */
/*   Updated: 2022/03/05 08:53:29 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_main(t_format *fm)
{
	if (ft_strequ(fm->mod, "L"))
		build_float(fm, va_arg(fm->ap, long double));
	else
		build_float(fm, va_arg(fm->ap, double));
}

static void	build_prefix(t_format *fm)
{
	if (fm->neg)
		fm->prefix = ft_strdup("-");
	else if (ft_strchr(fm->flags, '+'))
		fm->prefix = ft_strdup("+");
	else if (ft_strchr(fm->flags, ' '))
		fm->prefix = ft_strdup(" ");
}

void	f_conv(t_format *fm)
{
	build_main(fm);
	build_prefix(fm);
}
