#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define RED_COLOR "[1;31m"
#define GREEN_COLOR "[1;32m"
#define BLUE_COLOR "[1;34m"
#define BG_RED_COLOR "[1;41m"
#define BG_BLUE_COLOR "[1;44m"

#define END_COLOR "\033[0m"



typedef struct		s_node
{
    int				data;
    struct s_node	*next;
}					t_node;

typedef struct	s_stack {
    t_node		*top;
    int			size_;
    int			size_started;
	int			(*is_empty)(struct s_stack *stack);
	void		(*push)(struct s_stack *stack, int data);
	void		(*pop)(struct s_stack *stack);
}				t_stack;

void	init(t_stack **stack);
int		is_sorted(t_stack *stack);
void	print_stack(t_stack *stack);
void print_stacks(t_stack *stack1, t_stack *stack2);
void	clear(t_stack **stack);



void sa_sb_ss(t_stack *stack1, t_stack *stack2, int operation);
void pa_pb(t_stack *stack1, t_stack *stack2, int operation);

#endif