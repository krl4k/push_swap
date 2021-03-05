#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct		s_node
{
    int				data;
    struct s_node	*next;
}					t_node;

typedef struct	s_stack {
    t_node		*top;
    int			size_;
	int			(*is_empty)(struct s_stack *stack);
	void		(*push)(struct s_stack *stack, int data);
	void		(*pop)(struct s_stack *stack);
}				t_stack;

void	init(t_stack **stack);
int		is_sorted(t_stack *stack);
void	print_stack(t_stack *stack);
void	clear(t_stack **stack);

#endif