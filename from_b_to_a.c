/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 21:53:28 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/28 21:53:29 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		choose_a_element(t_stack *a, t_stack *b, int b_index)
{
	int		curr_index;
	int		prev_index;

	curr_index = a->mk_head;
	if (b->nums[b_index].index < a->nums[curr_index].index)
	{
		prev_index = curr_index == 0 ? a->len - 1 : curr_index - 1;
		while (b->nums[b_index].index < a->nums[prev_index].index &&
				a->nums[curr_index].index > a->nums[prev_index].index)
		{
			curr_index = prev_index;
			prev_index = prev_index == 0 ? a->len - 1 : prev_index - 1;
		}
	}
	else
	{
		while (b->nums[b_index].index > a->nums[curr_index].index &&
				a->nums[curr_index].index < a->nums[(curr_index + 1) == a->len ? 0 : curr_index + 1].index)
			curr_index = curr_index + 1 == a->len ? 0 : curr_index + 1;
		if (b->nums[b_index].index > a->nums[curr_index].index &&
				a->nums[curr_index].index > a->nums[(curr_index + 1) == a->len ? 0 : curr_index + 1].index)
			curr_index = curr_index + 1 == a->len ? 0 : curr_index + 1;
	}
	return (curr_index);
}

int		count_required_rotations(t_stack *a, t_stack *b, int a_index, int b_index, bool *a_rev, bool *b_rev)
{
	int		i;
	int		min_index;
	int		a_r_count;
	int		a_rr_count;
	int		b_r_count;
	int		b_rr_count;
	int		*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * 5);
	a_r_count = a_index;
	a_rr_count = a->len - a_index;
	b_r_count = b_index;
	b_rr_count = b->len - b_index;
	arr[0] = a_r_count >= b_r_count ? a_r_count : b_r_count;
	arr[1] = a_r_count + b_rr_count;
	arr[2] = b_r_count + a_rr_count;
	arr[3] = a_rr_count >= b_rr_count ? a_rr_count : b_rr_count;
	min_index = 0;
	while (i < 4)
	{
		if (arr[i] < arr[min_index])
			min_index = i;
		i++;
	}
	if (min_index == 0)
	{
		*a_rev = false;
		*b_rev = false;
	}
	else if (min_index == 1)
	{
		*a_rev = false;
		*b_rev = true;
	}
	else if (min_index == 2)
	{
		*a_rev = true;
		*b_rev = false;
	}
	else if (min_index == 3)
	{
		*a_rev = true;
		*b_rev = true;
	}
	return (arr[min_index]);
}

void	choose_elements(t_stack *a, t_stack *b, t_info *info)
{
	int		i;
	bool	a_rev;
	bool	b_rev;
	int		test_b_index;
	int		test_a_index;
	int		start_rotation_counts;
	int		current_rotation_counts;

	i = 1;
	test_a_index = choose_a_element(a, b, 0);
	info->a_elm_index = test_a_index;
	info->b_elm_index = 0;
	start_rotation_counts = count_required_rotations(a, b, test_a_index, 0, &a_rev, &b_rev);
	info->a_reverse = a_rev;
	info->b_reverse = b_rev;
	while (i < b->len)
	{
		test_b_index = i;
		test_a_index = choose_a_element(a, b, test_b_index);
		current_rotation_counts = count_required_rotations(a, b, test_a_index, test_b_index, &a_rev, &b_rev);
		if (current_rotation_counts < start_rotation_counts)
		{
			info->a_elm_index = test_a_index;
			info->b_elm_index = test_b_index;
			info->a_reverse = a_rev;
			info->b_reverse = b_rev;
			start_rotation_counts = current_rotation_counts;
		}
		i++;
	}
}

void	do_rotations(t_stack *a, t_stack *b, t_info *info)
{
	int		a_val;
	int		b_val;

	a_val = a->nums[info->a_elm_index].index;
	b_val = b->nums[info->b_elm_index].index;
	while (a->nums[0].index != a_val || b->nums[0].index != b_val)
	{
		if (info->a_reverse == info->b_reverse
			&& a->nums[0].index != a_val
			&& b->nums[0].index != b_val)
			(info->a_reverse == true) ? rrr_operation(a, b) : rr_operation(a, b);
		else if (a->nums[0].index != a_val)
			(info->a_reverse == true) ? rrotate_operation(a, true) : rotate_operation(a, true);
		else if (b->nums[0].index != b_val)
			(info->b_reverse == true) ? rrotate_operation(b, true) : rotate_operation(b, true);
	}
}

void	send_b_to_a(t_stack *a, t_stack *b)
{
	t_info	info;

	while (b->len != 0)
	{
		choose_elements(a, b, &info);
		do_rotations(a, b, &info);
		push_operation(b, a);
	}
}