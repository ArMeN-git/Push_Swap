/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:47:15 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/21 17:47:17 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef	struct	s_info
{
	int			a_elm_index;
	int			b_elm_index;
	bool		a_reverse;
	bool		b_reverse;
}				t_info;

typedef	struct	s_num
{
	int			value;
	int			index;
	bool		keep;
}				t_num;

typedef	struct	s_stack
{
	t_num		*nums;
	int			len;
	int			mk_head;
	int			mk_head_val;
	char		id;
}				t_stack;

void	ft_putstr(char *str);
void	exit_with_error();
int		ft_atoi_modified(char **str);
void	fill_stack(int argc, char **argv);
void	start_solution(t_stack *a, t_stack *b);
void	swap_operation(t_stack *s, bool print);
void	push_operation(t_stack *s1, t_stack *s2);
void	rotate_operation(t_stack *s, bool print);
void	rrotate_operation(t_stack *s, bool print);
void	rr_operation(t_stack *a, t_stack *b);
void	rrr_operation(t_stack *a, t_stack *b);
void	indexing(t_stack *a);
void	keep_or_send(t_stack *a);
int		markup_elems(t_stack *a, int mk_start_index);
int		test_markup(t_stack *a, int mk_start_index);
int		count_keep_elems(t_stack *a);
void	send_a_to_b(t_stack *a, t_stack *b);
void	send_b_to_a(t_stack *a, t_stack *b);
void	fix_stack_a(t_stack *a);

#endif