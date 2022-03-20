/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 08:36:25 by hbui              #+#    #+#             */
/*   Updated: 2022/03/20 12:48:51 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define COLOR_RANGE 18

enum e_color
{
	EOC,
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	BOLD_BLACK,
	BOLD_RED,
	BOLD_GREEN,
	BOLD_YELLOW,
	BOLD_BLUE,
	BOLD_MAGENTA,
	BOLD_CYAN,
	BOLD_WHITE
};

typedef struct s_format
{
	va_list		ap;
	int			prec;
	int			min_width;
	char		mod[10];
	char		*prefix;
	char		*suffix;
	char		*main;
	char		flags[10];
	char		conv;
	int			neg;
	int			is_null_char;
}	t_format;

typedef void	t_conv(t_format *fm);

void		build_num(t_format *fm, long long num, const unsigned int base);
void		build_unum(t_format *fm, unsigned long long num,
				const unsigned int base);
void		build_float(t_format *fm, long double num);

void		b_conv(t_format *fm);
void		d_conv(t_format *fm);
void		f_conv(t_format *fm);
void		c_conv(t_format *fm);
void		s_conv(t_format *fm);
void		p_conv(t_format *fm);
void		o_conv(t_format *fm);
void		u_conv(t_format *fm);
void		x_conv(t_format *fm);
void		xx_conv(t_format *fm);
void		perc_conv(t_format *fm);

int			get_flag(t_format *fm, const char **format);
int			get_min_width(t_format *fm, const char **format);
int			get_precision(t_format *fm, const char **format);
int			get_modifier(t_format *fm, const char **format);
int			get_conv(t_format *fm, const char **format);

void		build(t_format *fm);
int			print_color(const char *str);
int			ft_printf(const char *format, ...);

#endif