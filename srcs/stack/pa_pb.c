#include "stack.h"

/*
**  push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty
*/

/*
** stack1  get
** stack2  put
*/

static void moving_tops(t_stack *stack1, t_stack *stack2)
{
	t_node *temp;

	temp = NULL;
	if (!stack1 || !stack2 || stack1 == stack2)
		return;
	if (!stack1->top)
		return;
	temp = stack1->top;
	stack1->top = temp->next;
	temp->next = NULL;
	stack1->size_--;
	if (!stack2->top)
		stack2->top = temp;
	else
	{
		temp->next = stack2->top;
		stack2->top = temp;
	}
	stack2->size_++;
}

void pa_pb(t_stack *stack1, t_stack *stack2, int operation)
{
	if (operation == 4)
		moving_tops(stack2, stack1);
	if (operation == 5)
		moving_tops(stack1, stack2);
}