/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:11:04 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/28 19:11:05 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		partition(t_num arr[], int low, int high)
{
	int		pivot = arr[high].value;

	int		lowIndex = (low - 1);
	int		tmp;

	for (int j = low; j < high; j++)
	{
		if (arr[j].value <= pivot)
		{
			lowIndex++;

			tmp = arr[lowIndex].value;
			arr[lowIndex] = arr[j];
			arr[j].value = tmp;
		}
	}

	tmp = arr[lowIndex + 1].value;
	arr[lowIndex + 1] = arr[high];
	arr[high].value = tmp;

	return (lowIndex + 1);
}

void	quick_sort(t_num arr[], int low, int high)
{
	if (low < high)
	{
		int	partIndex = partition(arr, low, high);

		quick_sort(arr, low, partIndex - 1);
		quick_sort(arr, partIndex + 1, high);
	}
}

t_num	*copy_arr(t_stack *a)
{
	int		i;
	t_num	*res;

	i = 0;
	res = (t_num *)malloc(sizeof(t_num) * (a->len + 1));
	while (i < a->len)
	{
		res[i] = a->nums[i];
		i++;
	}
	return (res);
}

void	indexing(t_stack *a)
{
	int		i;
	int		j;
	t_num	*copy;

	i = 0;
	copy = copy_arr(a);
	quick_sort(copy, 0, a->len - 1);
	while (i < a->len)
	{
		j = 0;
		while (j < a->len)
		{
			if (a->nums[i].value == copy[j].value)
			{
				a->nums[i].index = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
}