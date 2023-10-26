/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 01:08:11 by eescalei          #+#    #+#             */
/*   Updated: 2023/10/26 14:57:10 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_snbr(t_stack *stack_a)
{
	t_stack *temp;

	temp = stack_a;
	while (temp != NULL)
	{
		if(temp->moves < stack_a->moves)
			stack_a = temp;
		temp = temp->next;	
	}
	return(stack_a);
}

int calc_moves(t_stack **stack_a, t_stack **stack_b)// ultimo else fica moves = index menor + diferenca da posicao +1   difenca de posicao como calcular se estiver um de cada lado do centro ?? nova variavel de stack com contagem de numeros total??
{
	t_stack *temp;
	if(!(*stack_b))
		return(0);
	// (*stack_a)->moves = find_correct_place((*stack_a)->content, *stack_b)->index +1;
	// (*stack_a) = (*stack_a)->next;
	do
	{
		temp = find_correct_place((*stack_a)->content, *stack_b);
		if(temp->direction == 1 && (*stack_a)->direction == 1)
			((*stack_a)->index > temp->index) ? ((*stack_a)->moves = (*stack_a)->index +2) : ((*stack_a)->moves = temp->index +2);
		else if(temp->direction == -1 && (*stack_a)->direction == -1)
			((*stack_a)->index > temp->index) ? ((*stack_a)->moves = (*stack_a)->index +2) : ((*stack_a)->moves = temp->index +2);// broken 97 second element 
		else
			(*stack_a)->moves = (*stack_a)->index + temp->index +2;
		if((*stack_a)->next)
			*stack_a = (*stack_a)->next;
		else
			break;
	}while((*stack_a));
	get_first_element(&(*stack_a));
	return(0);// possible otimization // maybe something wrong with 97
}

t_stack *find_correct_place(int number, t_stack *stack_b) // criar caso para ultimo stack
{
	t_stack *temp_b;
	temp_b = stack_b->next;
	while(temp_b->next)
	{
		if (stack_b->content > number > temp_b->content)
			return(temp_b);
		temp_b = temp_b->next;
		stack_b = stack_b->next;
	}// progresso 1
	if (stack_b->content > number > temp_b->content)
		return(temp_b);
	while(stack_b->previous)
		stack_b = stack_b->previous;
	return(stack_b);// NAO LE O ULTIMO ELEMENTO
}

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
			while(i++ < temp_b->index) // corrected 96
				rrb(&(*stack_b));
		else if (temp_b->direction == 1)
			while(i++ <= temp_b->index )
				rb(&(*stack_b));
		pb(&(*stack_a), &(*stack_b));
	}
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
	calc_moves(&(*stack_a), &(*stack_b));
	print_stack(*stack_a, *stack_b);
	printf("%i\n", find_correct_place(9999, *stack_b)->content); //teste
	while(ft_lstsize(*stack_a) > 96)
	{
		temp_a = find_snbr(*stack_a);
		get_first_element(&(*stack_a));
		temp_b = find_correct_place(temp_a->content, *stack_b);
		get_first_element(&(*stack_b));
		printf("mover:%i para cima de:%i\n",find_snbr(*stack_a)->content, find_correct_place(temp_a->content, *stack_b)->content);
		move_nbr(&(*stack_a), temp_a, temp_b, &(*stack_b));
		calc_moves(&(*stack_a), &(*stack_b));
	}
	// while(ft_lstsize(*stack_b) > 0)
	// {
	// 	if(ft_lstlast(*stack_a)->content > (*stack_b)->content)
	// 		rra(&(*stack_a));
	// 	pa(&(*stack_a), &(*stack_b));
	// }	
}