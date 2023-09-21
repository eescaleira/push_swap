/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:53:50 by eescalei          #+#    #+#             */
/*   Updated: 2023/09/21 19:46:07 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// criar erro para limitede int
// criar caso para dois args

int main (int ac, char **av)
{
	int i;
	int j;
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *temp;
	
	if(ac < 3)
	{
		printf("not enough arguments!");
		return (-1);
	}
	
	/* verificar valores nao numericos*/
	i = 1;
	while(av[i] != NULL)
	{
		j = 0;
		while(av[i][j] != '\0')
		{
			if(av[i][j] > 57)
			{
				printf("Error\n");
				return(-1);
			}
			j++;
		}
		i++;
	}
	
	/* verificar valores iguais */
	i = 1;
	j = 2;
	while(av[i] != NULL)
	{
		while(av[j] != NULL)
		{
			if(ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				printf("Error\n");
				return(-1);
			}
			j++;
		}
		i++;
		j = i +1;
	}
	
	/* criar lista A */
	i = 1;
	while(av[i] != NULL)
	{
		if(av[i])
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(av[i])));
		else
			printf("erro a criar lista inicial");
		i++;
	}
	variables_corretor(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	sa(&stack_b);
	rra(&stack_b);
	calc_moves(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// sort_stack(&stack_a, &stack_b);	


	/* CRIAR FILE E FUNCTION Para print dos stacks */
	/* visualizacao de lista a */
	int c = 1;
	if(stack_a)
	{
		printf("%i       %i   index: %i  direction: %i  moves:%i\n", c++, stack_a->content, stack_a->index, stack_a->direction, stack_a->moves);
		while (stack_a->next != NULL)
		{
			stack_a = stack_a->next;
			printf("%i       %i   index: %i  direction: %i  moves:%i\n", c++, stack_a->content, stack_a->index, stack_a->direction, stack_a->moves);
		} 
		/* check previous A */
		printf("\n");
		// while(stack_a->previous != NULL)
		// {
		// 	printf("%i   index: %i  direction: %i\n", stack_a->content, stack_a->index, stack_a->direction);		
		// 	stack_a = stack_a->previous;
		// }
		// printf("%i   index: %i  direction: %i\n", stack_a->content, stack_a->index, stack_a->direction);
	}	
	
	/* visualizacao de lista b */	
	if(stack_b)
	{
		printf("\n");
		while (stack_b->next != NULL)
		{
			printf("%i   index: %i  direction: %i\n", stack_b->content, stack_b->index, stack_b->direction);
			stack_b = stack_b->next;
		} 
		printf("%i   index: %i  direction: %i \n", stack_b->content, stack_b->index, stack_b->direction);
		printf("\n");
		/* check previous B */
		// while(stack_b->previous != NULL)
		// {
		// 	printf("%i   index: %i  direction: %i\n", stack_b->content, stack_b->index, stack_b->direction);		
		// 	stack_b = stack_b->previous;
		// }
		// printf("%i   index: %i  direction: %i\n", stack_b->content, stack_b->index, stack_b->direction);
	}
}
