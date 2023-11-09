/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:08:11 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/09 15:11:48 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_nbr1(t_stack **stack_a, t_stack *ta, t_stack *tb, t_stack **stack_b)
{
	if (ta->direction == 1)
	{
		if (ta->index > tb->index)
		{
			ta->index = ta->index - tb->index;
			while (tb->index-- > 0)
				rr(&(*stack_a), &(*stack_b));
			while (ta->index-- > 0)
				ra(&(*stack_a));
		}
		else
		{
			tb->index = tb->index - ta->index;
			while (ta->index-- > 0)
				rr(&(*stack_a), &(*stack_b));
			while (tb->index-- > 0)
				rb(&(*stack_b));
		}
	}
	else
		move_nbr2(&(*stack_a), ta, tb, &(*stack_b));
	return (0);
}

int	move_nbr(t_stack **stack_a, t_stack *ta, t_stack *tb, t_stack **stack_b)
{
	if (ta->direction != tb->direction)
	{
		if (ta->direction == 1)
		{
			while (ta-> index-- > 0)
				ra(&(*stack_a));
			while (tb-> index-- > 0)
				rrb(&(*stack_b));
		}
		else
		{
			while (tb->index-- > 0)
				rb(&(*stack_b));
			while (ta-> index-- > 0)
				rra(&(*stack_a));
		}
	}
	else if (ta->direction == tb->direction)
		move_nbr1(&(*stack_a), ta, tb, &(*stack_b));
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
	t_stack	*ta;
	t_stack	*tb;

	ta = find_snbr(*stack_a);
	get_first_element(&(*stack_a));
	tb = find_correct_place(ta->content, *stack_b);
	get_first_element(&(*stack_b));
	move_nbr(&(*stack_a), ta, tb, &(*stack_b));
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
		if (temp->content < (*stack_a)->content 
			&& temp->content > (*stack_b)->content)
			rra(&(*stack_a));
	}
	pa(&(*stack_a), &(*stack_b));
	if ((*stack_a)->content > ft_lstlast(*stack_a)->content)
		rra(&(*stack_a));
	return (0);
}
