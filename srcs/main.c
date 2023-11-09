/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:53:50 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/09 18:44:56 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// criar erro para limitede int
// criar caso para dois args (mais?)
// caso nao haja argumentos ??
// se ja estiver sorted
// arg "1 3 0 4"// separar
int	check_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] > 57)
			{
				printf("Error\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_2(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (av[i] != NULL)
	{
		while (av[j] != NULL)
		{
			if (ft_atoii(av[i]) == ft_atoii(av[j]))
			{
				printf("Error\n");
				return (-1);
			}
			j++;
		}
		i++;
		j = i +1;
	}
	return (0);
}

t_stack *push_swap(t_stack **stack_a, t_stack **stack_b)
{
	variables_corretor(&(*stack_a));
	sort_stack(&(*stack_a), &(*stack_b));
	print_stack(*stack_a, *stack_b);
	return (*stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;
	int		i;
	
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 3)
	{
		printf("not enough arguments!");
		return (0);
	}
	if (check_input(&(*av)) != 0 || check_2(&(*av)) != 0)
		return (0);
	i = 1;
	while (av[i] != NULL)
	{
		if (av[i])
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoii(av[i])));
		else
			printf("erro a criar lista inicial");
		i++;
	}
	push_swap(&stack_a, &stack_b);
	return (0);
}
