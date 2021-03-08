#include "stack.h"

void reverse_rotate(t_stack *stack)
{
	t_node *temp;
	t_node *before_temp;

	if (!stack || !stack->top)
		return;
	if (stack->size_ > 1)
	{
		temp = stack->top;
		while (temp->next)
		{
			before_temp = temp;
			temp = temp->next;
		}
		temp->next = stack->top;
		stack->top = temp;
		before_temp->next = NULL;
	}
}

void rra_rrb_rrr(t_stack *stack1, t_stack *stack2, int operation)
{
	if (operation == 9)
		reverse_rotate(stack1);
	if (operation == 10)
		reverse_rotate(stack2);
	if (operation == 11)
	{
		reverse_rotate(stack1);
		reverse_rotate(stack2);
	}
}