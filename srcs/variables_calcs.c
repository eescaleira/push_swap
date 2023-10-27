
#include "push_swap.h"


void get_first_element(t_stack **stack)
{
	while((*stack)->previous != NULL)
		(*stack) = (*stack)->previous;
}


void variables_corretor(t_stack **stack_a)
{
	int i;
	int stack_size;
	get_first_element(&(*stack_a));
	i = 1;
	stack_size = ft_lstsize(*stack_a) + 1;
	(*stack_a)->position = i;
	(*stack_a)->index = i++ -1;
	(*stack_a)->direction = 1;
	(*stack_a)->previous = NULL;
	while ((*stack_a)->next != NULL)
	{
		(*stack_a)->next->previous = *stack_a;
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->position = i;
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



 