/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:38:06 by hbui              #+#    #+#             */
/*   Updated: 2021/11/30 21:32:20 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	transform(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			s[i] = '\0';
			i++;
		}
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	char	*dup;
	int		str_len;
	char	**split;

	i = 0;
	dup = ft_strdup(s);
	if (!dup)
		return (NULL);
	str_len = ft_strlen(s);
	split = (char **)ft_memalloc(sizeof(char *) * (transform(dup, c) + 1));
	if (!split)
		return (NULL);
	c = 0;
	while (i < str_len)
	{
		while (i < str_len && !dup[i])
			i++;
		if (i < str_len)
			split[c++] = ft_strdup(dup + i);
		while (i < str_len && dup[i])
			i++;
	}
	free(dup);
	return (split);
}
