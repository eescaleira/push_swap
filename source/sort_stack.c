/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:08:11 by eescalei          #+#    #+#             */
/*   Updated: 2023/09/26 20:07:47 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int move_nbr(t_stack **stack_a, t_stack *temp_a, t_stack *temp_b, t_stack **stack_b)
{
	int i;
	
	i = 0;
	if (temp_a->direction == 1  && temp_b->direction == 1)
	{
		if(temp_a->index <= temp_b->index)
		{
			while(i++ <= temp_a->index)
				rr(&(*stack_a), &(*stack_b));
			while(i++ <= temp_b->index)
				rb(&(*stack_b));
		}
		else
		{
			while(i++ <= temp_b->index)
				rr(&(*stack_a), &(*stack_b));
			while(i++ <= temp_a->index)
				ra(&(*stack_a));
		}
		pb(&(*stack_a), &(*stack_b));
	}
	else if (temp_a->direction == -1  && temp_b->direction == -1)
	{
		if(temp_a->index <= temp_b->index)
		{
			while(i++ <= temp_a->index)
				rrr(&(*stack_a), &(*stack_b));
			while(i++ <= temp_b->index)
				rrb(&(*stack_b));
		}
		else
		{
			while(i++ <= temp_b->index)
				rrr(&(*stack_a), &(*stack_b));
			while(i++ <= temp_a->index)
				rra(&(*stack_a));
		}
		pb(&(*stack_a), &(*stack_b));
	}
	else
	{
		if(temp_a->direction == -1)
			while(i++ <= temp_a->index)
				rra(&(*stack_a));
		else if(temp_a->direction == 1)
			while(i++ <= temp_a->index)
				ra(&(*stack_a));
		i = 0;
		if (temp_b->direction == -1)
			while(i++ <= temp_b->index)
				rrb(&(*stack_b));
		else if (temp_b->direction == 1)
			while(i++ <= temp_b->index)
				rb(&(*stack_b));
		pb(&(*stack_a), &(*stack_b));
	}
}

int find_correct_place(int number, t_stack **stack_b) // criar caso para ultimo stack
{
	t_stack *temp_b;
	temp_b = (*stack_b);
	while(temp_b ->next != NULL)
	{
		if(temp_b->next->content > number)
			(*stack_b) = temp_b;
		temp_b = temp_b->next;	
	}
	return(0);
}

int find_snbr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	temp = (*stack_a);
	while (temp != NULL)
	{
		if(temp->moves < (*stack_a)->moves)
			*stack_a = temp;
		temp = temp->next;	
	}
	return(0);
}



int sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	
	pb(&(*stack_a), &(*stack_b));
	pb(&(*stack_a), &(*stack_b));
	if((*stack_b)->content < (*stack_b)->next->content)
		sb(&(*stack_b));
	pb(&(*stack_a), &(*stack_b));
	if ((*stack_b)->content < ft_lstlast(*stack_b)->content)
		rb(&(*stack_b));
	else if((*stack_b)->content < (*stack_b)->next->content)
		sb(&(*stack_b));
	while(ft_lstsize(*stack_a) > 96)
	{
		calc_moves(&(*stack_a), &(*stack_b));
		find_snbr(&(*stack_a), &(*stack_b));
		temp_a = (*stack_a);
		get_first_element(&(*stack_a));
		find_correct_place(temp_a->content, &(*stack_b));
		temp_b = (*stack_b);
		printf("temp_b->content: %i\n", (*stack_b)->next->index);
		get_first_element(&(*stack_b));
		move_nbr(&(*stack_a), temp_a, temp_b, &(*stack_b));
	}
	// while(ft_lstsize(*stack_b) > 0)
	// {
	// 	if(ft_lstlast(*stack_a)->content > (*stack_b)->content)
	// 		rra(&(*stack_a));
	// 	pa(&(*stack_a), &(*stack_b));
	// }	
}