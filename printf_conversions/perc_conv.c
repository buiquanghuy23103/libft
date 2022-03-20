/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:21:41 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 10:28:55 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_main(t_format *fm)
{
	fm->main = ft_strdup("%");
}

void	perc_conv(t_format *fm)
{
	build_main(fm);
}
