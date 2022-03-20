/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:35:01 by hbui              #+#    #+#             */
/*   Updated: 2022/03/04 12:44:16 by huybui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char *const	g_color_str[COLOR_RANGE] = {
[EOC] = "{eoc}",
[BLACK] = "{black}",
[RED] = "{red}",
[GREEN] = "{green}",
[YELLOW] = "{yellow}",
[BLUE] = "{blue}",
[MAGENTA] = "{magenta}",
[CYAN] = "{cyan}",
[WHITE] = "{white}",
[BOLD_BLACK] = "{bold black}",
[BOLD_RED] = "{bold red}",
[BOLD_GREEN] = "{bold green}",
[BOLD_YELLOW] = "{bold yellow}",
[BOLD_BLUE] = "{bold blue}",
[BOLD_MAGENTA] = "{bold magenta}",
[BOLD_CYAN] = "{bold cyan}",
[BOLD_WHITE] = "{bold white}"
};

static const char *const	g_color_code[COLOR_RANGE] = {
[EOC] = "\e[0m",
[BLACK] = "\e[0;30m",
[RED] = "\e[0;31m",
[GREEN] = "\e[0;32m",
[YELLOW] = "\e[0;33m",
[BLUE] = "\e[0;34m",
[MAGENTA] = "\e[0;35m",
[CYAN] = "\e[0;36m",
[WHITE] = "\e[0;37m",
[BOLD_BLACK] = "\e[1;30m",
[BOLD_RED] = "\e[1;31m",
[BOLD_GREEN] = "\e[1;32m",
[BOLD_YELLOW] = "\e[1;33m",
[BOLD_BLUE] = "\e[1;34m",
[BOLD_MAGENTA] = "\e[1;35m",
[BOLD_CYAN] = "\e[1;36m",
[BOLD_WHITE] = "\e[1;37m"
};

static int	begin_width(const char *haystack, const char *needle)
{
	int	i;

	i = -1;
	if (!needle)
		return (0);
	while (needle[++i])
	{
		if (haystack[i] != needle[i])
			return (0);
	}
	return (i);
}

int	print_color(const char *str)
{
	int	i;

	i = -1;
	while (++i < COLOR_RANGE)
	{
		if (begin_width(str, g_color_str[i]))
		{
			ft_putstr(g_color_code[i]);
			return (ft_strlen(g_color_str[i]));
		}
	}
	return (1);
}
