/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:40:51 by hbui              #+#    #+#             */
/*   Updated: 2022/03/06 20:47:25 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	satisfy_min_width(t_format *fm)
{
	int		len;
	char	*temp;
	int		prefix_len;
	int		copy_position;

	prefix_len = ft_strlen(fm->prefix);
	len = fm->min_width - ft_strlen(fm->main) - fm->is_null_char;
	if (len <= prefix_len)
		return ;
	temp = ft_strnew(len);
	ft_memset(temp, ' ', len);
	if (ft_strchr(fm->flags, '-'))
	{
		temp[len - prefix_len] = '\0';
		fm->suffix = temp;
		return ;
	}
	if ((fm->prec == -1 || !ft_strchr("diouxX", fm->conv))
		&& ft_strchr(fm->flags, '0'))
		ft_memset(temp, '0', len);
	copy_position = (len - prefix_len) * (temp[0] != '0');
	if (fm->prefix)
		ft_strncpy(temp + copy_position, fm->prefix, prefix_len);
	ft_strdel(&fm->prefix);
	fm->prefix = temp;
}

static void	init_dispatcher(t_conv *func[128])
{
	ft_bzero(func, sizeof(t_conv *) * 128);
	func['b'] = b_conv;
	func['c'] = c_conv;
	func['d'] = d_conv;
	func['f'] = f_conv;
	func['i'] = d_conv;
	func['s'] = s_conv;
	func['o'] = o_conv;
	func['x'] = x_conv;
	func['X'] = xx_conv;
	func['p'] = p_conv;
	func['u'] = u_conv;
	func['%'] = perc_conv;
}

void	build(t_format *fm)
{
	t_conv	*func[128];

	init_dispatcher(func);
	if (!fm->conv)
		return ;
	func[(int)fm->conv](fm);
	satisfy_min_width(fm);
}
