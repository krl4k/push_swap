#include "stack.h"

/*
** swap - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements).
*/

static void swap(t_stack *stack)
{
	t_node *temp;

	temp = NULL;
	if (stack)
	{
		if (stack->size_ > 1)
		{
			temp = stack->top;
			stack->top = stack->top->next;
			temp->next = stack->top->next;
			stack->top->next = temp;
		}
	}
}

static void swap_two(t_stack *stack1, t_stack *stack2)
{
	if (stack1)
		swap(stack1);
	if (stack2)
		swap(stack2);
}

void sa_sb_ss(t_stack *stack1, t_stack *stack2, int operation)
{
	if (operation == 1)
		swap(stack1);
	if (operation == 2)
		swap(stack2);
	if (operation == 3)
		swap_two(stack1, stack2);
}