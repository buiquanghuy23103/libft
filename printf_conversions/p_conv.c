/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:31:02 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 10:28:37 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_main(t_format *fm)
{
	build_unum(fm, (unsigned long)va_arg(fm->ap, void *), 16);
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
	ft_strncpy(fm->prefix, "0x", 2);
}

void	p_conv(t_format *fm)
{
	build_main(fm);
	if (fm->prec == 0 && fm->main[0] == '0')
		fm->main[0] = '\0';
	build_prefix(fm);
}
