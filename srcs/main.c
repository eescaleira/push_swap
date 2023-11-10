/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:53:50 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/10 18:02:20 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
				write(1, "Error\n", 6);
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
			if(ft_atoii(av[j]) == -1 || ft_atoii(av[i]) == -1 || ft_atoii(av[i]) == ft_atoii(av[j]))
			{
				write(1, "Error\n", 6);
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
	if(ft_lstsize(*stack_a) == 2)
	{	if ((*stack_a)->content > (*stack_a)->next->content)
			sa(&(*stack_a));
		return (*stack_a);
	}
	variables_corretor(&(*stack_a));
	sort_stack(&(*stack_a), &(*stack_b));
	print_stack(*stack_a, *stack_b);
	return (*stack_a);
}

int ac_check(int ac)
{
	if (ac <= 2)
	{
		write(1, "Error\n", 6);
		return (-1);		
	}	
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;
	int		i;
	
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (check_input(&(*av)) != 0 || check_2(&(*av)) != 0 || ac_check(ac) != 0)
		return (0);
	i = 1;
	while (av[i] != NULL)
	{
		if (av[i])
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoii(av[i])));
		else
			write(1, "Error\n", 6);
		i++;
	}
	push_swap(&stack_a, &stack_b);
	return (0);
}
