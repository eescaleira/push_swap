/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:56:21 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/03 19:00:09 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoii(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' 
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

int	move_nbr2(t_stack **stack_a, t_stack *ta, t_stack *tb, t_stack **stack_b)
{
	if (ta->index > tb->index)
	{
		ta->index = ta->index - tb->index;
		while (tb->index-- > 0)
			rrr(&(*stack_a), &(*stack_b));
		while (ta->index-- > 0)
			rra(&(*stack_a));
	}
	else
	{
		tb->index = tb->index - ta->index;
		while (ta->index-- > 0)
			rrr(&(*stack_a), &(*stack_b));
		while (tb->index-- > 0)
			rrb(&(*stack_b));
	}
	return (0);
}
