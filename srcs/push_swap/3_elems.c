#include "push_swap.h"

void three_elems(t_stack *stack)
{
	t_node *temp;

	if (!stack)
		return;
	temp = stack->top;
	if (temp->data > temp->next->data && temp->data < temp->next->next->data)
		sa_sb_ss(stack, NULL, SA);
	if (temp->data > temp->next->data && temp->next->data > temp->next->next->data)
	{
		sa_sb_ss(stack, NULL, SA);
		rra_rrb_rrr(stack, NULL, RRA);
	}
	if (temp->data > temp->next->data && temp->next->data < temp->next->next->data)
		ra_rb_rr(stack, NULL, RA);
	if (temp->data < temp->next->data && temp->next->data > temp->next->next->data)
	{
		sa_sb_ss(stack, NULL, SA);
		ra_rb_rr(stack, NULL, RA);
	}
	if (temp->data < temp->next->data && temp->data > temp->next->next->data)
		rra_rrb_rrr(stack, NULL, RRA);
}

