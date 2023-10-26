/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:53:50 by eescalei          #+#    #+#             */
/*   Updated: 2023/10/26 23:09:01 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// criar erro para limitede int
// criar caso para dois args (mais?)
// caso nao haja argumentos ??
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
	sort_stack(&stack_a, &stack_b);	
	print_stack(stack_a, stack_b);
	return 0;
}
