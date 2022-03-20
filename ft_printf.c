/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 08:24:29 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 10:38:05 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getinfo(t_format *fm, const char **format)
{
	char	*temp;

	++(*format);
	if (!(**format))
		return (0);
	temp = (char *)*format;
	*format += get_flag(fm, format);
	*format += get_min_width(fm, format);
	*format += get_precision(fm, format);
	*format += get_modifier(fm, format);
	*format += get_conv(fm, format);
	return (*format - temp);
}

static void	reset(t_format *fm)
{
	fm->prec = -1;
	fm->min_width = -1;
	fm->is_null_char = 0;
	fm->conv = 0;
	fm->neg = 0;
	fm->prefix = 0;
	ft_bzero(fm->mod, sizeof(fm->mod));
	ft_bzero(fm->flags, sizeof(fm->flags));
	fm->prefix = NULL;
	fm->main = NULL;
	fm->suffix = NULL;
}

static int	print(t_format *fm)
{
	int	count;

	count = 0;
	count += write(1, fm->prefix, ft_strlen(fm->prefix));
	ft_strdel(&fm->prefix);
	if (fm->is_null_char)
		count += write(1, "\0", 1);
	else
		count += write(1, fm->main, ft_strlen(fm->main));
	ft_strdel(&fm->main);
	count += write(1, fm->suffix, ft_strlen(fm->suffix));
	ft_strdel(&fm->suffix);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	t_format	fm;
	int			count;
	int			color;

	count = 0;
	va_start(fm.ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			reset(&fm);
			if (!getinfo(&fm, &format))
				continue ;
			build(&fm);
			count += print(&fm);
		}
		else if (*format == '{' && ft_set(&color, print_color(format)) != 1)
			format += color;
		else
			count += write(1, format++, 1);
	}
	va_end(fm.ap);
	return (count);
}
