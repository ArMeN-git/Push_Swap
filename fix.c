/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 21:45:30 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/30 21:45:31 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_min_place(t_stack *a)
{
	int		i;

	i = 0;
	while (i < a->len)
	{
		if (a->nums[i].index == 0)
			return (i);
		i++;
	}
	return (0);
}

void	fix_stack_a(t_stack *a)
{
	int		min_index;
	bool	is_reverse;

	min_index = get_min_place(a);
	is_reverse = (min_index <= (a->len - min_index)) ? false : true;
	while (a->nums[0].index != 0)
		is_reverse ? rrotate_operation(a, true) : rotate_operation(a, true);
}