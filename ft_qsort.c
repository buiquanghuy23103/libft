/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:09:37 by hbui              #+#    #+#             */
/*   Updated: 2022/04/13 13:56:53 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_pivot(int *input_arr, size_t arr_size)
{
	size_t	smaller_count;
	size_t	larger_count;
	size_t	pivot_i;
	size_t	i;
	int		pivot;

	smaller_count = 0;
	i = 0;
	pivot_i = 0;
	if (arr_size < 3)
		return (input_arr[0]);
	while (pivot_i < arr_size && i < arr_size)
	{
		pivot = input_arr[pivot_i];
		if (input_arr[i] < pivot)
			smaller_count++;
		if (smaller_count > arr_size / 2 || larger_count > arr_size / 2)
		{
			i = 0;
			smaller_count = 0;
			larger_count = 0;
			pivot_i++;
		}
		else
			i++;
	}
	return (pivot);
}

void	ft_qsort(int *input_arr, size_t arr_size)
{
	int		pivot;
	size_t	i;
	size_t	swap;

	i = 0;
	if (!input_arr || arr_size < 2)
		return ;
	pivot = find_pivot(input_arr, arr_size);
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
