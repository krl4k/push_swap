#include "stack.h"

int size(t_stack *stack)
{
	if (stack)
		return stack->size_;
	return 0;
}

int is_empty(t_stack *stack)
{
	if (size(stack) > 0)
		return (0);
	return (1);
}


void pop(t_stack *stack)
{
	if (size(stack) > 0)
	{
		t_node *oldTop;
		oldTop = (stack)->top;
		(stack)->top = oldTop->next;
		free(oldTop);
		oldTop = NULL;
		(stack)->size_--;
	}
}

void push(t_stack *stack, int data)
{

	t_node *new_elem;

	new_elem= (t_node *)malloc(sizeof(t_node));
	new_elem->data = data;
	if (is_empty(stack))
	{
		(stack)->top = new_elem;
		new_elem->next = NULL;
		(stack)->size_ = 0;
	}
	else
	{
		new_elem->next = stack->top;
		stack->top = new_elem;
	}
	stack->size_++;
}

void init(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->size_ = 0;
	(*stack)->push = push;
	(*stack)->pop = pop;
	(*stack)->is_empty = is_empty;
}
