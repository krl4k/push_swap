#include "stack.h"
#include "colors.h"
#include "libft.h"

void print_stack(t_stack *stack)
{
	t_node *current;

	ft_putstr_fd(BLUE_COLOR"Stack info\n"END_COLOR, 1);
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
		ft_putendl_fd("", 1);
		current = current->next;
	}
	ft_putstr_fd(END_COLOR, 1);
}
