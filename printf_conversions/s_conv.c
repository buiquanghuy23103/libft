/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:12:29 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 10:29:30 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	build_main(t_format *fm)
{
	char	*str;

	str = va_arg(fm->ap, char *);
	if (str)
		fm->main = ft_strdup(str);
	else
		fm->main = ft_strdup("(null)");
	if (fm->prec > 0 && (size_t)fm->prec < ft_strlen(fm->main))
		fm->main[fm->prec] = '\0';
}

void	s_conv(t_format *fm)
{
	build_main(fm);
	if (fm->prec == 0)
		fm->main[0] = '\0';
}
