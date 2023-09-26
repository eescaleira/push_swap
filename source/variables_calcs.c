
#include "push_swap.h"


void get_first_element(t_stack **stack)
{
	while((*stack)->previous != NULL)
		(*stack) = (*stack)->previous;
}

int calc_moves(t_stack **stack_a, t_stack **stack_b)// ultimo else fica moves = index menor + diferenca da posicao +1   difenca de posicao como calcular se estiver um de cada lado do centro ?? nova variavel de stack com contagem de numeros total??
{
	t_stack *temp;
	temp = (*stack_a);
	if(!stack_b)
		return(0);
	while((*stack_a)->next)
	{
		if(find_correct_place((*stack_a)->content, &(*stack_b)) == 1)
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

void variables_corretor(t_stack **stack_a)
{
	int i;
	int stack_size;
	get_first_element(&(*stack_a));
	i = 1;
	stack_size = ft_lstsize(*stack_a) + 1;
	(*stack_a)->index = i++ -1;
	(*stack_a)->direction = 1;
	(*stack_a)->previous = NULL;
	while ((*stack_a)->next != NULL)
	{
		(*stack_a)->next->previous = *stack_a;
		(*stack_a) = (*stack_a)->next;
		if(i > stack_size/2)
			(*stack_a)->direction = -1;
		else
			(*stack_a)->direction = 1;
		if((*stack_a)->direction == 1)
			(*stack_a)->index = i++ -1;
		else
			(*stack_a)->index = stack_size - i++ ;
	}
	get_first_element(&(*stack_a));
}



 