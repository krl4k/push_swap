#include "stack.h"

void clear(t_stack **stack)
{
    if (!*stack)
        return;
    while (!(*stack)->is_empty(*stack))
		(*stack)->pop(*stack);
    free(*stack);
    *stack = NULL;
}
