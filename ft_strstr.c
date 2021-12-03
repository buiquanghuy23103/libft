/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:32:37 by hbui              #+#    #+#             */
/*   Updated: 2021/12/03 17:28:16 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	haystack_len;
	int	needle_len;

	i = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	if (needle_len < haystack_len)
	{
		while (haystack[i])
		{
			if (haystack[i] == needle[0]
				&& ft_strncmp(haystack + i, needle, needle_len) == 0)
				return ((char *) haystack + i);
			i++;
		}
	}
	return (NULL);
}
