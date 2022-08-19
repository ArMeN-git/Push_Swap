/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:47:08 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/23 19:47:09 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_sorting_logic(t_stack *a, t_stack *b)
{
	indexing(a);
	keep_or_send(a);
	send_a_to_b(a, b);
	send_b_to_a(a, b);
	fix_stack_a(a);
}

void	three_numbers_algorithm(t_stack *a)
{
	int		x;
	int		y;
	int		z;

	x = a->nums[0].value;
	y = a->nums[1].value;
	z = a->nums[2].value;
	if (x > y && y > z)
	{
		rotate_operation(a, true);
		swap_operation(a, true);
	}
	else if (x < z && z < y)
	{
		swap_operation(a, true);
		rotate_operation(a, true);
	}
	else if (y < x && x < z)
		swap_operation(a, true);
	else if (y < z && z < x)
		rotate_operation(a, true);
	else
		rrotate_operation(a, true);
}

void	start_solution(t_stack *a, t_stack *b)
{
	if (a->len == 2)
	{
		swap_operation(a, true);
		return ;
	}
	else if (a->len == 3)
	{
		three_numbers_algorithm(a);
		return ;
	}
	else
		main_sorting_logic(a, b);
}