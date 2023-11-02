/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_A.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:54:04 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/02 15:51:50 by eescalei         ###   ########.fr       */
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
	printf("sa\n");
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
	printf("pa\n");
	return (0);
}

int	ra(t_stack **stack_a)
{
	if (*stack_a)
		get_first_element(&(*stack_a));
	if (!*stack_a || ft_lstsize(*stack_a) < 2)
		return (-1);
	rotate(&(*stack_a));
	printf("ra\n");
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
	printf("rra\n");
	return (0);
}
