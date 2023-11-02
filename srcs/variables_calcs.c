/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_calcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 10:30:26 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/02 18:43:44 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!(*stack_b))
		return (0);
	do
	{
		temp = find_correct_place((*stack_a)->content, *stack_b);
	if (temp->direction == 1 && (*stack_a)->direction == 1)
	{
		if ((*stack_a)->index > temp->index) 
			((*stack_a)->moves = (*stack_a)->index +1);
		else	
			((*stack_a)->moves = temp->index +1);
	}
	else if(temp->direction == -1 && (*stack_a)->direction == -1)
		((*stack_a)->index > temp->index) ? ((*stack_a)->moves = (*stack_a)->index +1) : ((*stack_a)->moves = temp->index +1);// broken 97 second element 
	else
		(*stack_a)->moves = (*stack_a)->index + temp->index +1;
	if ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	else
		break;
	}while ((*stack_a));
	get_first_element(&(*stack_a));
	return (0);
}

t_stack	*find_snbr(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp != NULL)
	{
		if (temp->moves < stack_a->moves)
			stack_a = temp;
		temp = temp->next;
	}
	return (stack_a);
}

void get_first_element(t_stack **stack)
{
	while((*stack)->previous != NULL)
		(*stack) = (*stack)->previous;
}


void variables_corretor(t_stack **stack_a)
{
	int i;
	int stack_size;
	get_first_element(&(*stack_a));
	i = 1;
	stack_size = ft_lstsize(*stack_a) + 1;
	(*stack_a)->position = i;
	(*stack_a)->index = i++ -1;
	(*stack_a)->direction = 1;
	(*stack_a)->previous = NULL;
	while ((*stack_a)->next != NULL)
	{
		(*stack_a)->next->previous = *stack_a;
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->position = i;
		if (i > stack_size/2)
			(*stack_a)->direction = -1;
		else
			(*stack_a)->direction = 1;
		if ((*stack_a)->direction == 1)
			(*stack_a)->index = i++ -1;
		else
			(*stack_a)->index = stack_size - i++ ;
	}
	get_first_element(&(*stack_a));
}
 