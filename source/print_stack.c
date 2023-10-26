/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:43:50 by eescalei          #+#    #+#             */
/*   Updated: 2023/10/24 23:58:57 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void print_stack(t_stack *stack_a, t_stack *stack_b)
{
	printf("Stack A                                                               Stack B\n");
	printf("------------------------------------------------------------------    ------------------------------------------------------------------\n");	
	while(stack_a || stack_b)
	{
		if(stack_a)
		{
			printf("| %5i | content:%5i | index:%3i | direction:%2i | moves:%5i |    ", stack_a->position, stack_a->content, stack_a->index, stack_a->direction, stack_a->moves);
			stack_a = stack_a->next;
		}
		if(stack_b)
		{
			printf("| %5i | content:%5i | index:%3i | direction:%2i | moves:%5i |", stack_b->position, stack_b->content, stack_b->index, stack_b->direction, stack_b->moves);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
	printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
}