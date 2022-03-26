/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:09:58 by hbui              #+#    #+#             */
/*   Updated: 2022/03/26 11:25:31 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	up(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

void	xx_conv(t_format *fm)
{
	x_conv(fm);
	up(fm->main);
	up(fm->prefix);
}
