/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:53:50 by eescalei          #+#    #+#             */
/*   Updated: 2023/10/27 10:52:23 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// criar erro para limitede int
// criar caso para dois args (mais?)
// caso nao haja argumentos ??
// se ja estiver sorted
// arg "1 3 0 4"// separar
int main (int ac, char **av)
{
	int i;
	int j;
	t_stack *stack_a;
	t_stack *stack_b;
	
	if(ac < 3)
	{
		printf("not enough arguments!");
		return (-1);
	}
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
	sort_stack(&stack_a, &stack_b);	
	return 0;
}
