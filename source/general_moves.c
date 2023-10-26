/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:53:59 by eescalei          #+#    #+#             */
/*   Updated: 2023/09/14 19:25:17 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap(t_stack **stack)
{
	if(ft_lstsize(*stack) <= 1)
		return	(-1);
	t_stack *temp;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->previous = NULL;
	temp->previous = *stack;
	if(temp->next)
		temp->next->previous = temp;
	variables_corretor(&(*stack));
	return(0);
}

int push(t_stack **destiny, t_stack **origin)
{
	t_stack *temp;
	// if podem sair  ??
	if(ft_lstsize(*origin) == 1)
	{
		(*destiny)->previous = *origin;
		(*destiny)->previous->next = *destiny;
		(*origin) = NULL;
	}
	else if(!*destiny)
	{
		*origin = (*origin)->next;
		*destiny = (*origin)->previous;
		(*destiny)->next = NULL;
		(*origin)->previous = NULL;
	}
	else
	{
		temp = *origin;
		*origin = (*origin)->next;
		temp->next = *destiny;
		(*origin)->previous = NULL;
		(*destiny)->previous = temp;
		temp->previous = NULL;
	}
	variables_corretor(&(*destiny));
	variables_corretor(&(*origin));
	return(0);
}
int rotate(t_stack **stack)
{
	t_stack *temp;
	temp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = temp;
	(*stack)->next->previous = *stack;
	*stack = temp->next;
	temp->next = NULL;
	(*stack)->previous = NULL;
	variables_corretor(&(*stack));
	return (0);
}

int reverse_rotate(t_stack **stack)
{
	t_stack *temp;
	temp = *stack;
	*stack = ft_lstlast(*stack);
	(*stack)->next = temp;
	(*stack)->previous->next = NULL;
	(*stack)->previous = NULL;
	(*stack)->next->previous = *stack;
	variables_corretor(&(*stack));
	return (0);
}