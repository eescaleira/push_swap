/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:53:43 by eescalei          #+#    #+#             */
/*   Updated: 2023/10/27 21:51:18 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct	stack
{
	struct stack	*previous;
	int				position;
	int				content;
	int				index;
	int 			direction;
	int 			moves;
	struct stack	*next;
}				t_stack;
/* algorythm */
int sort_stack(t_stack **stack_a, t_stack **stack_b);
int calc_moves(t_stack **stack_a, t_stack **stack_b);
t_stack *find_correct_place(int number, t_stack *stack_b);
t_stack *find_snbr(t_stack *stack_a);

/* suport functions */
int	ft_atoii(char *str);
void print_stack(t_stack *stack_a, t_stack *stack_b);

/* list functions */
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);

/* variables corretion */
void variables_corretor(t_stack **stack_a);
void get_first_element(t_stack **stack);

/* general moves */
int swap(t_stack **stack);
int push(t_stack **destiny, t_stack **origin);
int rotate(t_stack **stack);
int reverse_rotate(t_stack **stack);

/* avaliable moves */
int sa(t_stack **stack_a);
int sb(t_stack **stack_b);
int ss(t_stack **stack_a, t_stack **stack_b);
int pa(t_stack **stack_a, t_stack **stack_b);
int pb(t_stack **stack_a, t_stack **stack_b);
int ra(t_stack **stack_a);
int rb(t_stack **stack_b);
int rr(t_stack **stack_a, t_stack **stack_b);
int rra(t_stack **stack_a);
int rrb(t_stack **stack_b);
int rrr(t_stack **stack_a, t_stack **stack_b);

#endif