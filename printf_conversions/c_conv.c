/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:26:00 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 10:28:05 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_main(t_format *fm)
{
	fm->main = ft_strnew(1);
	fm->main[0] = (char)va_arg(fm->ap, int);
	fm->is_null_char = !fm->main[0];
}

void	c_conv(t_format *fm)
{
	build_main(fm);
}
