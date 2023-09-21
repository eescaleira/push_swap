
#include "push_swap.h"

int find_corect_place(int number, t_stack **stack_b)
{
	while((*stack_b)->content > number && (*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	if((*stack_b)->content > number && (*stack_b)->next == NULL)
		return(1);
	return(0);
}


void variables_corretor(t_stack **stack)
{
	int i;
	int stack_size;
	get_first_element(&(*stack));
	i = 1;
	stack_size = ft_lstsize(*stack) + 1;
	(*stack)->index = i++ -1;
	(*stack)->direction = 1;
	(*stack)->previous = NULL;
	while ((*stack)->next != NULL)
	{
		(*stack)->next->previous = *stack;
		(*stack) = (*stack)->next;
		if(i > stack_size/2)
			(*stack)->direction = -1;
		else
			(*stack)->direction = 1;
		if((*stack)->direction == 1)
			(*stack)->index = i++ -1;
		else
			(*stack)->index = stack_size - i++ ;
	}
	get_first_element(&(*stack));
}

void get_first_element(t_stack **stack)
{
	while((*stack)->previous != NULL)
		(*stack) = (*stack)->previous;
}

int calc_moves(t_stack **stack_a, t_stack **stack_b)// ultimo else fica moves = index menor + diferenca da posicao +1   difenca de posicao como calcular se estiver um de cada lado do centro ?? nova variavel de stack com contagem de numeros total??
{
	while((*stack_a)->next != NULL)
	{
		if(find_corect_place((*stack_a)->content, &(*stack_b)) == 1)
			(*stack_a)->moves = (*stack_a)->index +2;
		else if(((*stack_b)->direction == -1 && (*stack_a)->direction == -1) || ((*stack_b)->direction == 1 && (*stack_a)->direction == 1))
		{
			(*stack_a)->moves = (*stack_a)->index +1; 
			if((*stack_a)->index < (*stack_b)->index)
				(*stack_a)->moves = (*stack_b)->index +1;
		}
		else
			(*stack_a)->moves = (*stack_a)->index + (*stack_b)->index +1;
		get_first_element(&(*stack_b));
		(*stack_a) = (*stack_a)->next;
	}
	get_first_element(&(*stack_a));
	return(0);
}
 