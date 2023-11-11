/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:54:04 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/11 13:09:05 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **stack_a)
{
	if (*stack_a)
		get_first_element(&(*stack_a));
	if (!*stack_a || ft_lstsize(*stack_a) < 2)
		return (-1);
	swap(&(*stack_a));
	write(1, "sa\n", 3);
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return (-1);
	if (*stack_a)
		get_first_element(&(*stack_a));
	get_first_element(&(*stack_b));
	push(&(*stack_a), &(*stack_b));
	write(1, "pa\n", 3);
	return (0);
}

int	ra(t_stack **stack_a)
{
	if (*stack_a)
		get_first_element(&(*stack_a));
	if (!*stack_a || ft_lstsize(*stack_a) < 2)
		return (-1);
	rotate(&(*stack_a));
	write(1, "ra\n", 3);
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (*stack_a)
		get_first_element(&(*stack_a));
	if (!*stack_a || ft_lstsize(*stack_a) < 2)
		return (-1);
	get_first_element(&(*stack_a));
	reverse_rotate(&(*stack_a));
	write(1, "rra\n", 4);
	return (0);
}
