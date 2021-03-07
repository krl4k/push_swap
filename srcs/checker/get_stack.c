#include "checker.h"

int is_number(const char *str)
{
	int i;
	int nbr;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error_handler(2);
		i++;
	}
	if (i > 10)
		return (0);
	if (i > 2)
	{
		nbr = ft_atoi(str);
		if (nbr == 0)
			error_handler(2);
		if (nbr < 0 && str[0] != -1)
			error_handler(2);

	}
	return (1);
}

int *get_number(char *str, int begin, int end)
{
//	int i;
	int *nbr;

//	i = 0;
	if (end - begin > 10)
		error_handler(2);

	nbr = (int *)malloc(sizeof(int));
	if (nbr == 0)
		error_handler(2);
	*nbr = ft_atoi(str);
	if ((*nbr < 0 && str[0] != '-') || (end - begin > 1 && *nbr == 0))
		error_handler(2);
	return (nbr);
}

int 	is_same_value(int *array, int count, int value)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (array[i] == value)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int is_valid_string(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (!ft_isdigit(str[i]))
			error_handler(2);
		k++;
		i++;
	}
	if (k > 10)
		return (0);
	return (1);
}

// todo min_INT
void check_string(t_list **list, char *str)
{
	int	i;
	int k;
	int	*nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if(is_valid_string(&str[i]))
		{
			k = 0;
			while (str[i + k] != '\0' && str[i + k] != ' ')
				k++;
			nbr = get_number(str, i, k);
			ft_lstadd_back(list, ft_lstnew(nbr));
			i += (k - 1);
		}
		i++;
	}
}

void 	list_to_array(t_list *list, int *stack)
{
	t_list *temp;
	int i;

	i = 0;
	temp = list;
	while (temp)
	{
		stack[i] = (*((int *)(temp->content)));
		if (is_same_value(stack, i, stack[i]))
			error_handler(2);
		i++;
		temp = temp->next;
	}
	ft_lstclear(&list, ft_lstfree_cont);
}


int		*get_stack_in_array(int ac, char **av)
{
	int i;
	int *stack;
	t_list *numbers_list;

	numbers_list = NULL;
	i = 1;
	while (i < ac)
	{
		check_string(&numbers_list, av[i]);
		i++;
	}
	printf("worked!\n");
	stack = (int *)ft_calloc(ft_lstsize(numbers_list), sizeof(int));
	if (!stack)
		error_handler(0);
	list_to_array(numbers_list, stack);

	return (stack);
}


void array_to_stack(t_stack *stack, int *stack_array, int count)
{
	int i;

	i = count;
	while (i >= 0)
	{
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