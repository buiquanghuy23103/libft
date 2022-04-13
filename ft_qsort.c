/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:09:37 by hbui              #+#    #+#             */
/*   Updated: 2022/04/13 10:25:32 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort(int *input_arr, size_t arr_size)
{
	int		pivot;
	size_t	i;
	size_t	swap;

	i = 0;
	if (arr_size < 2)
		return ;
	pivot = input_arr[0];
	while (++i < arr_size)
	{
		if (input_arr[i] <= pivot)
		{
			swap = i;
			while (swap > 0 && input_arr[swap - 1] >= pivot)
			{
				ft_swap(input_arr + swap - 1, input_arr + swap);
				swap--;
			}
		}
	}
	i = 0;
	while (i < arr_size && input_arr[i] != pivot)
		i++;
	ft_qsort(input_arr, i + 1);
	ft_qsort(input_arr + i + 1, arr_size - i - 1);
}