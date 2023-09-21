/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:54:04 by eescalei          #+#    #+#             */
/*   Updated: 2023/09/13 04:03:09 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int sa(t_stack **stack_a)
{
	if(*stack_a)
		get_first_element(&(*stack_a));
	if(!*stack_a || ft_lstsize(*stack_a) < 2)
		return	(-1);	
	swap(&(*stack_a));
	printf("sa\n");
	return (0);
}

int sb(t_stack **stack_b)
{
	if(*stack_b)
		get_first_element(&(*stack_b));
	if(!*stack_b || ft_lstsize(*stack_b) <= 1)
		return	(-1);
	swap(&(*stack_b));
	printf("sb\n");
	return (0);
}

int ss(t_stack **stack_a, t_stack **stack_b)
{
	if(*stack_b)
		get_first_element(&(*stack_b));
	if(*stack_a)
		get_first_element(&(*stack_a));
	if(!*stack_a || ft_lstsize(*stack_a) <= 1)
		swap(&(*stack_a));
	if(!*stack_b || ft_lstsize(*stack_b) <= 1)
		swap(&(*stack_b));
	printf("ss\n");
	return (0);
}
int pa(t_stack **stack_a, t_stack **stack_b)
{
	if(!*stack_b)
		return	(-1);
	if(*stack_a)
		get_first_element(&(*stack_a));
	get_first_element(&(*stack_b));
	push(&(*stack_a), &(*stack_b));
	printf("pa\n");
	return (0);
}
int pb(t_stack **stack_a, t_stack **stack_b)
{
	if(!*stack_a)
		return	(-1);
	get_first_element(&(*stack_a));
	if(*stack_b)
		get_first_element(&(*stack_b));
	push(&(*stack_b), &(*stack_a));
	printf("pb\n");
	return (0);
}

int ra(t_stack **stack_a)
{
	if(*stack_a)
		get_first_element(&(*stack_a));
	if(!*stack_a ||ft_lstsize(*stack_a) < 2)
		return (-1);
	rotate(&(*stack_a));
	printf("ra\n");
	return (0);
}

int rb(t_stack **stack_b)
{
	if(*stack_b)
		get_first_element(&(*stack_b));
	if(!*stack_b ||ft_lstsize(*stack_b) < 2)
		return (-1);
	rotate(&(*stack_b));
	printf("rb\n");
	return (0);
}
int rr(t_stack **stack_a, t_stack **stack_b)
{
	if(*stack_b)
		get_first_element(&(*stack_b));
	if(*stack_a)
		get_first_element(&(*stack_a));
	if(!*stack_a ||ft_lstsize(*stack_a) > 2)
		rotate(&(*stack_a));
	if(!stack_b ||ft_lstsize(*stack_b) > 2)
		rotate(&(*stack_b));
	printf("rr\n");
	return (0);
}

int rra(t_stack **stack_a)
{
	if(*stack_a)
		get_first_element(&(*stack_a));
	if(!*stack_a ||ft_lstsize(*stack_a) < 2)
		return (-1);
	get_first_element(&(*stack_a));
	reverse_rotate(&(*stack_a));
	printf("rra\n");
	return (0);
}
int rrb(t_stack **stack_b)
{
	if(*stack_b)
		get_first_element(&(*stack_b));
	if(!*stack_b ||ft_lstsize(*stack_b) < 2)
		return (-1);
	reverse_rotate(&(*stack_b));
	printf("rrb\n");
	return (0);
}
int rrr(t_stack **stack_a, t_stack **stack_b)
{
	if(*stack_b)
		get_first_element(&(*stack_b));
	if(*stack_a)
		get_first_element(&(*stack_a));
	if(ft_lstsize(*stack_a) > 2)
		reverse_rotate(&(*stack_a));
	if(ft_lstsize(*stack_b) > 2)
		reverse_rotate(&(*stack_b));
	printf("rrr\n");
	return (0);
}
