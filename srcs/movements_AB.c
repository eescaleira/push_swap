/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_AB.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:46:48 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/02 15:54:40 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
		get_first_element(&(*stack_b));
	if (*stack_a)
		get_first_element(&(*stack_a));
	if (!*stack_a || ft_lstsize(*stack_a) <= 1)
		swap(&(*stack_a));
	if (!*stack_b || ft_lstsize(*stack_b) <= 1)
		swap(&(*stack_b));
	printf("ss\n");
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
		get_first_element(&(*stack_b));
	if (*stack_a)
		get_first_element(&(*stack_a));
	if (!*stack_a || ft_lstsize(*stack_a) > 2)
		rotate(&(*stack_a));
	if (!stack_b || ft_lstsize(*stack_b) > 2)
		rotate(&(*stack_b));
	printf("rr\n");
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
		get_first_element(&(*stack_b));
	if (*stack_a)
		get_first_element(&(*stack_a));
	if (ft_lstsize(*stack_a) > 2)
		reverse_rotate(&(*stack_a));
	if (ft_lstsize(*stack_b) > 2)
		reverse_rotate(&(*stack_b));
	printf("rrr\n");
	return (0);
}
