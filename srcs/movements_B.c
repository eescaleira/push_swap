/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_B.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:46:52 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/10 17:08:38 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_stack **stack_b)
{
	if (*stack_b)
		get_first_element(&(*stack_b));
	if (!*stack_b || ft_lstsize(*stack_b) <= 1)
		return (-1);
	swap(&(*stack_b));
	write(1, "sb\n", 3);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return (-1);
	get_first_element(&(*stack_a));
	if (*stack_b)
		get_first_element(&(*stack_b));
	push(&(*stack_b), &(*stack_a));
	write(1, "pb\n", 3);
	return (0);
}

int	rb(t_stack **stack_b)
{
	if (*stack_b)
		get_first_element(&(*stack_b));
	if (!*stack_b || ft_lstsize(*stack_b) < 2)
		return (-1);
	rotate(&(*stack_b));
	write(1, "rb\n", 3);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (*stack_b)
		get_first_element(&(*stack_b));
	if (!*stack_b || ft_lstsize(*stack_b) < 2)
		return (-1);
	reverse_rotate(&(*stack_b));
	write(1, "rrb\n", 4);
	return (0);
}
