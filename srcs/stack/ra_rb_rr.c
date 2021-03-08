#include "stack.h"

void rotate(t_stack *stack)
{
	t_node *temp;
	t_node *old_top;

	if (!stack || !stack->top)
		return;
	if (stack->size_ > 1)
	{
		old_top = stack->top;
		temp = stack->top;
		while (temp->next)
			temp =  temp->next;
		temp->next = old_top;
		stack->top = old_top->next;
		old_top->next = NULL;
	}
}


void rr(t_stack *stack1, t_stack *stack2)
{
	rotate(stack1);
	rotate(stack2);
}

void ra_rb_rr(t_stack *stack1, t_stack *stack2, int operation)
{
	if (operation == 6)
		rotate(stack1);
	if (operation == 7)
		rotate(stack1);
	if (operation == 8)
		rr(stack1, stack2);
}