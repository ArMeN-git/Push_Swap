/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:53:13 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/28 21:53:15 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	has_false_elems(t_stack *a)
{
	int		i;

	i = 0;
	while (i < a->len)
	{
		if (!a->nums[i].keep)
			return (true);
		i++;
	}
	return (false);
}

int		get_mk_index(t_stack *a, int val)
{
	int		i;

	i = 0;
	while (i < a->len)
	{
		if (a->nums[i].value == val)
			return (i);
		i++;
	}
	return (0);
}

bool	is_sa_required(t_stack *a)
{
	int		now;
	int		after;

	now = count_keep_elems(a);
	swap_operation(a, false);
	a->mk_head = get_mk_index(a, a->mk_head_val);
	after = test_markup(a, a->mk_head);
	swap_operation(a, false);
	if (after > now)
		return (true);
	return (false);
}

void	send_a_to_b(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	while (has_false_elems(a))
	{
		if (is_sa_required(a))
		{
			swap_operation(a, true);
			a->mk_head = get_mk_index(a, a->mk_head_val);
			markup_elems(a, a->mk_head);
		}
		else if (!a->nums[0].keep)
			push_operation(a, b);
		else
			rotate_operation(a, true);
		a->mk_head = get_mk_index(a, a->mk_head_val);
	}
}