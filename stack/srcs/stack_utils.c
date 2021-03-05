#include "stack.h"

int		is_sorted(t_stack *stack)
{
	t_node *current;

	current = stack->top;
	while (current->next)
	{
		if (current->data > current->next->data)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}