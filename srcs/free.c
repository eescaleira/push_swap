/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:40:16 by eescalei          #+#    #+#             */
/*   Updated: 2023/11/11 14:27:58 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	free(*stack);
}
