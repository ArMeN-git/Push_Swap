/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_modified.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 21:30:37 by argrigor          #+#    #+#             */
/*   Updated: 2021/06/21 21:30:39 by argrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_modified(char **str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
    if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
        (*str)++;
	}
	if (!(**str >= '0' && **str <= '9'))
        exit_with_error();
	while (**str >= '0' && **str <= '9')
	{
		res = res * 10 + (**str - '0');
		(*str)++;
	}
    if (**str && !(**str == ' ' || (**str >= 9 && **str <= 13)))
        exit_with_error();
	if ((res * sign) > INT_MAX || (res * sign) < INT_MIN)
		exit_with_error();
	return (res * sign);
}