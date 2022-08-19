/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:27:09 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/21 18:27:10 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_operation(t_stack *s, bool print)
{
	int		i;
	t_num	temp;

	if (s->len >= 2)
	{
		temp = s->nums[s->len - 1];
		i = s->len - 1;
		while (i > 0)
		{
			s->nums[i] = s->nums[i - 1];
			i--;
		}
		s->nums[0] = temp;
	}
	if (print)
	{	
		if (s->id == 'a')
			ft_putstr("rra\n");
		else
			ft_putstr("rrb\n");
	}
}

void	rrr_operation(t_stack *a, t_stack *b)
{
	rrotate_operation(a, false);
	rrotate_operation(b, false);
	ft_putstr("rrr\n");
}

void	rotate_operation(t_stack *s, bool print)
{
	int		i;
	t_num	temp;

	if (s->len >= 2)
	{
		temp = s->nums[0];
		i = 0;
		while (i < s->len - 1)
		{
			s->nums[i] = s->nums[i + 1];
			i++;
		}
		s->nums[s->len - 1] = temp;
	}
	if (print)
	{	
		if (s->id == 'a')
			ft_putstr("ra\n");
		else
			ft_putstr("rb\n");
	}
}

void	rr_operation(t_stack *a, t_stack *b)
{
	rotate_operation(a, false);
	rotate_operation(b, false);
	ft_putstr("rr\n");
}

void	push_operation(t_stack *s1, t_stack *s2)
{
	if (s1->len >= 1)
	{
		s2->len++;
		rrotate_operation(s2, false);
		s2->nums[0] = s1->nums[0];
		rotate_operation(s1, false);
		s1->len--;
	}
	if (s1->id == 'a')
		ft_putstr("pb\n");
	else
		ft_putstr("pa\n");
}

void	swap_operation(t_stack *s, bool print)
{
	t_num	temp;

	if (s->len >= 2)
	{
		temp = s->nums[0];
		s->nums[0] = s->nums[1];
		s->nums[1] = temp;
	}
	if (print)
	{
		if (s->id == 'a')
			ft_putstr("sa\n");
		else
			ft_putstr("sb\n");
	}
}