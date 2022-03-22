/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinfo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:29:42 by hbui              #+#    #+#             */
/*   Updated: 2022/03/02 12:37:22 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flag(t_format *fm, const char **format)
{
	int	i;

	i = 0;
	while (**format && ft_strchr("#0- +", (*format)[i]))
	{
		fm->flags[i] = (*format)[i];
		i++;
	}
	return (i);
}

int	get_min_width(t_format *fm, const char **format)
{
	int	count;

	count = 0;
	if (**format == '*' && ++(*format))
	{
		fm->min_width = va_arg(fm->ap, int);
		if (fm->min_width < 0)
		{
			ft_strcat(fm->flags, "-");
			fm->min_width *= -1;
		}
	}
	if (ft_isdigit(**format))
	{
		fm->min_width = ft_atoi(*format);
		count = ft_numlen(fm->min_width);
	}
	return (count);
}

int	get_precision(t_format *fm, const char **format)
{
	if (**format != '.')
		return (0);
	++(*format);
	fm->prec = 0;
	if (ft_isdigit(**format))
		fm->prec = ft_atoi(*format);
	else if (**format == '*')
	{
		fm->prec = va_arg(fm->ap, int);
		if (fm->prec < 0)
			fm->prec = -1;
		return (1);
	}
	else
		return (0);
	while (ft_isdigit(**format))
		++(*format);
	return (0);
}

int	get_modifier(t_format *fm, const char **format)
{
	int	i;

	i = 0;
	while (**format && ft_strchr("Llh", (*format)[i]))
	{
		fm->mod[i] = (*format)[i];
		i++;
	}
	return (i);
}

int	get_conv(t_format *fm, const char **format)
{
	if (**format && ft_strchr("bdiouxXscpf%", **format))
		fm->conv = **format;
	else
		return (0);
	return (1);
}
