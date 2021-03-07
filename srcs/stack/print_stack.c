#include "stack.h"
#include "libft.h"

void print_stack(t_stack *stack)
{
	t_node *current;

//	ft_putstr_fd(BLUE_COLOR"Stack info\n"END_COLOR, 1);
	if (stack->is_empty(stack))
	{
		ft_putstr_fd(RED_COLOR"Stack is empty\n"END_COLOR, 1);
		return;
	}
	ft_putstr_fd(RED_COLOR"Top = ", 1);
	ft_putnbr_fd(stack->top->data, 1);
	ft_putendl_fd(END_COLOR,1);
	current = stack->top;
	while (current != NULL)
	{
		ft_putstr_fd(GREEN_COLOR, 1);
		ft_putnbr_fd(current->data, 1);
		ft_putstr_fd("\t", 1);
		current = current->next;
	}
	ft_putendl_fd(END_COLOR, 1);
}


void print_stacks(t_stack *stack1, t_stack *stack2)
{
	t_node *temp1;
	t_node *temp2;

	temp1 = stack1->top;
	temp2 = stack2->top;

	ft_putstr_fd(BLUE_COLOR"Stack info\n"END_COLOR, 1);
	if (stack1->size_ > stack2->size_)
	{
		int res = stack1->size_ - stack2->size_;
		while (res > 0 && temp1)
		{
			printf("%d\n", temp1->data);
			temp1 = temp1->next;
			res--;
		}
	}
	else if (stack2->size_ > stack1->size_)
	{
		int res = stack2->size_ - stack1->size_;
		while (res > 0 && temp2)
		{
			printf(" %10d\n", temp2->data);
			temp2 = temp2->next;
			res--;
		}
	}
	if (temp1)
	{
		while (temp1->next)
		{
			printf("%d%10d\n", temp1->data, temp2->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		printf("%d%10d\n", temp1->data, temp2->data);
	}
}
