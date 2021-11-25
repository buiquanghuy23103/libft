/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:19:27 by hbui              #+#    #+#             */
/*   Updated: 2021/11/23 22:28:54 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*join;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = ft_strnew(s1_len + s2_len);
	if (!join)
		return (NULL);
	join[s1_len + s2_len] = '\0';
	while (i < s1_len)
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		join[s1_len + i] = s2[i];
		i++;
	}
	return (join);
}
