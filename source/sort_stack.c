/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:08:11 by eescalei          #+#    #+#             */
/*   Updated: 2023/09/17 02:27:38 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	pb(&(*stack_a), &(*stack_b));
	pb(&(*stack_a), &(*stack_b));
	if((*stack_a)->content < (*stack_a)->next->content)
		sa(&(*stack_a));
	while(ft_lstsize(*stack_a) > 3)
	{
		calc_moves(&(*stack_a), &(*stack_b));
		
	}
}