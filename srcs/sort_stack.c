/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:08:11 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/02 19:17:59 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_correct_place(int number, t_stack *stack_b)
{
	while (stack_b->next)
	{
		if (stack_b->content > stack_b->next->content && stack_b->content > number && number > stack_b->next->content)
			return (stack_b->next);
		if (stack_b->content < stack_b->next->content && (number > stack_b->next->content || number < stack_b->content))
			return (stack_b->next);
		stack_b = stack_b->next;
	}
	while (stack_b->previous)
		stack_b = stack_b->previous;
	return (stack_b);
}

int	move_nbr(t_stack **stack_a, t_stack *temp_a, t_stack *temp_b, t_stack **stack_b)
{
	if(temp_a->direction != temp_b->direction)
	{
		if(temp_a->direction == 1)
		{
			while(temp_a-> index-- > 0)
				ra(&(*stack_a));
			while(temp_b-> index-- > 0)
				rrb(&(*stack_b));
		}
		else
		{
			while(temp_b->index-- > 0)
				rb(&(*stack_b));
			while(temp_a-> index-- > 0)
				rra(&(*stack_a));
		}
	}
	else if(temp_a->direction == temp_b->direction)
	{
		if(temp_a->direction == 1)
		{
			if(temp_a->index > temp_b->index)
			{
				temp_a->index = temp_a->index - temp_b->index;
				while(temp_b->index-- > 0)
					rr(&(*stack_a), &(*stack_b));
				while(temp_a->index-- > 0)
					ra(&(*stack_a));
			}
			else
			{
				temp_b->index = temp_b->index - temp_a->index;
				while(temp_a->index-- > 0)
					rr(&(*stack_a), &(*stack_b));
				while(temp_b->index-- > 0)
					rb(&(*stack_b));
			}
		}
		else
		{
			if(temp_a->index > temp_b->index)
			{
				temp_a->index = temp_a->index - temp_b->index;
				while(temp_b->index-- > 0)
					rrr(&(*stack_a), &(*stack_b));
				while(temp_a->index-- > 0)
					rra(&(*stack_a));
			}
			else
			{
				temp_b->index = temp_b->index - temp_a->index;
				while (temp_a->index-- > 0)
					rrr(&(*stack_a), &(*stack_b));
				while (temp_b->index-- > 0)
					rrb(&(*stack_b));
			}
		}
		}
	pb(&(*stack_a), &(*stack_b));
	return (0);
}

int	innit_sort(t_stack **stack_a, t_stack **stack_b)
{
	pb(&(*stack_a), &(*stack_b));
	pb(&(*stack_a), &(*stack_b));
	if ((*stack_b)->content < (*stack_b)->next->content)
		sb(&(*stack_b));
	pb(&(*stack_a), &(*stack_b));
	if ((*stack_b)->content < ft_lstlast(*stack_b)->content)
		rb(&(*stack_b));
	else if ((*stack_b)->content < (*stack_b)->next->content)
		sb(&(*stack_b));
	calc_moves(&(*stack_a), &(*stack_b));
	return (0);
}

int	alghorythm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = find_snbr(*stack_a);
	get_first_element(&(*stack_a));
	temp_b = find_correct_place(temp_a->content, *stack_b);
	get_first_element(&(*stack_b));
	move_nbr(&(*stack_a), temp_a, temp_b, &(*stack_b));
	calc_moves(&(*stack_a), &(*stack_b));
	return (0);
}

int	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	innit_sort(&(*stack_a), &(*stack_b));
	while (ft_lstsize(*stack_a) > 1)
		alghorythm(&(*stack_a), &(*stack_b));
	while ((*stack_b)->content > (*stack_b)->next->content)
		rb(&(*stack_b));
	rb(&(*stack_b));
	temp = *stack_a;
	while (ft_lstsize(*stack_b) > 1)
	{
		pa(&(*stack_a), &(*stack_b));
		if (temp->content < (*stack_a)->content && temp->content > (*stack_b)->content)
			rra(&(*stack_a));
	}
	pa(&(*stack_a), &(*stack_b));
	if ((*stack_a)->content > ft_lstlast(*stack_a)->content)
		rra(&(*stack_a));
	return (0);
}
