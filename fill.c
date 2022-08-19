/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:45:22 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/21 20:45:23 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			count_nums(char *line)
{
	int		i;
	int		elems;

	i = 0;
	elems = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i])
		{
			while (line[i] && line[i] != ' ')
				i++;
			elems++;
		}
	}
	return (elems);
}

void	check_is_ordered(t_stack *stack)
{
	bool	ordered;
	int		i;

	ordered = true;
	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->nums[i].value >= stack->nums[i + 1].value)
			ordered = false;
		i++;
	}
	if (ordered)
		exit(0);
}

void	check_duplicates(t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < stack->len - 1)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->nums[i].value == stack->nums[j].value)
				exit_with_error();
			j++;
		}
		i++;
	}
}

void	fill_nums(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < stack->len)
	{
		if (*argv[j])
			stack->nums[i].value = ft_atoi_modified(&argv[j]);
		else
		{
			j++;
			if (j == argc)
				break;
			stack->nums[i].value = ft_atoi_modified(&argv[j]);
		}
		i++;
	}
}

void	fill_stack(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			arg_c;

	arg_c = argc;
	stack_a.len = 0;
	stack_b.len = 0;
	stack_a.id = 'a';
	stack_b.id = 'b';
	while (--arg_c >= 1)
		stack_a.len += count_nums(argv[arg_c]);
	if (!(stack_a.nums = (t_num *)malloc(sizeof(t_num) * stack_a.len)))
		exit_with_error();
	if (!(stack_b.nums = (t_num *)malloc(sizeof(t_num) * stack_a.len)))
		exit_with_error();
	fill_nums(argc, argv, &stack_a);
	check_duplicates(&stack_a);
	check_is_ordered(&stack_a);
	start_solution(&stack_a, &stack_b);
}