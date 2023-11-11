/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:56:21 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/11 13:11:02 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoii(char *str)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' 
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if ((nb * sign) > 2147483647 || (nb * sign) < -2147483648)
		return (-1);
	return (nb * sign);
}

void print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	
	i = 0;
	printf("Stack A                                                               Stack B\n");
	printf("------------------------------------------------------------------    ------------------------------------------------------------------\n");	
	while(stack_a || stack_b)
	{
		if(stack_a)
		{
			printf("| %5i | content:%5i | index:%3i | direction:%2i | moves:%5i |    ", stack_a->position, stack_a->content, stack_a->index, stack_a->direction, stack_a->moves);
			stack_a = stack_a->next;
		}
		if(stack_b)
		{
			if(i == 1)
				printf("                                                                      ");
			if(!stack_a)
				i = 1;
			printf("| %5i | content:%5i | index:%3i | direction:%2i | moves:%5i |", stack_b->position, stack_b->content, stack_b->index, stack_b->direction, stack_b->moves);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
	printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
}
