/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:37:40 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/28 19:37:42 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_keep_elems(t_stack *a)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < a->len)
	{
		if (a->nums[i].keep)
			count++;
		i++;
	}
	return (count);
}

int		test_markup(t_stack *a, int mk_start_index)
{
	int		count;
	int		cmp_index;
	int		stop;

	count = 1;
	cmp_index = mk_start_index;
	stop = a->nums[mk_start_index].value;
	mk_start_index = mk_start_index + 1 == a->len ? 0 : mk_start_index + 1;
	while (a->nums[mk_start_index].value != stop)
	{
		if (a->nums[mk_start_index].index == (a->nums[cmp_index].index + 1))
		{
			count++;
			cmp_index = mk_start_index;
		}
		mk_start_index++;
		if (mk_start_index == a->len)
			mk_start_index = 0;
	}
	return (count);
}

int		markup_elems(t_stack *a, int mk_start_index)
{
	int		cmp_index;
	int		stop;

	cmp_index = mk_start_index;
	a->nums[mk_start_index].keep = true;
	stop = a->nums[mk_start_index].value;
	mk_start_index = mk_start_index + 1 == a->len ? 0 : mk_start_index + 1;
	while (a->nums[mk_start_index].value != stop)
	{
		if (a->nums[mk_start_index].index == (a->nums[cmp_index].index + 1))
		{
			a->nums[mk_start_index].keep = true;
			cmp_index = mk_start_index;
		}
		else
			a->nums[mk_start_index].keep = false;
		mk_start_index++;
		if (mk_start_index == a->len)
			mk_start_index = 0;
	}
	return (count_keep_elems(a));
}

void	keep_or_send(t_stack *a)
{
	int		i;
	int		start_count;
	int		keep_count;

	i = 0;
	start_count = 0;
	a->mk_head = 0;
	while (i < a->len)
	{
		keep_count = markup_elems(a, i);
		if (keep_count > start_count)
		{
			a->mk_head = i;
			a->mk_head_val = a->nums[i].value;
			start_count = keep_count;
		}
		else if (keep_count == start_count && a->nums[i].value < a->nums[a->mk_head].value)
		{
			a->mk_head = i;
			a->mk_head_val = a->nums[i].value;
		}
		i++;
	}
	markup_elems(a, a->mk_head);
}