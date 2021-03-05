#include "checker.h"

int is_number(const char *str)
{
	int i;
	int nbr;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 10)
		return (0);
	if (i > 2)
	{
		nbr = ft_atoi(str);
		if (nbr <= 0)
			return (0);
	}
	return (1);
}

int is_same_value(int *array, int count, int value)
{
	int i;

	i = 0;
	while (i < count - 1)
	{
		if (array[i] == value)
			return (1);
		i++;
	}
	return (0);
}


int		*get_stack_in_array(int ac, char **av)
{
	int i;
	int *stack;

	i = 1;
	stack = (int *)ft_calloc(ac, sizeof(int));
	if (!stack)
		return (NULL);
	while (i < ac)
	{
		if (is_number(av[i]))
		{
			stack[i - 1] = ft_atoi(av[i]);
			if (i > 1)
			{
				if (is_same_value(stack, i, stack[i - 1])) {
					free(stack);
					return (NULL);
				}
			}
		}
		else
		{
			free(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

/*
** @param1  stack
** @param2  array
*/

void array_to_stack(t_stack *stack, int *stack_array, int count)
{
	int i;

	i = count;
	while (i >= 0)
	{
		printf("i = %d\n", i);
		stack->push(stack, stack_array[i]);
		i--;
	}
}

void get_stack(t_stack *stack1, int argc, char **argv)
{
	int		*stack_array;

	stack_array = get_stack_in_array(argc, argv);
	if (!stack_array)
		error_handler(2);
	array_to_stack(stack1, stack_array, argc - 2);
}