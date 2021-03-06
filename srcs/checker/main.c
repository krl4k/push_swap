/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:44:46 by fgrisell          #+#    #+#             */
/*   Updated: 2021/03/05 17:44:47 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "checker.h"




int get_operation(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (SA);
	else if (ft_strcmp(line, "sb") == 0)
		return (SB);
	else if (ft_strcmp(line, "ss") == 0)
		return (SS);
	else if (ft_strcmp(line, "pa") == 0)
		return (PA);
	else if (ft_strcmp(line, "pb") == 0)
		return (PB);
	else if (ft_strcmp(line, "ra") == 0)
		return (RA);
	else if (ft_strcmp(line, "rb") == 0)
		return (RB);
	else if (ft_strcmp(line, "rr") == 0)
		return (RR);
	else if (ft_strcmp(line, "rra") == 0)
		return (RRA);
	else if (ft_strcmp(line, "rrb") == 0)
		return (RRB);
	else if (ft_strcmp(line, "rrr") == 0)
		return (RRR);
	return (-1);
}

//void do_operation(t_stack *stack, t_stack *stack2, int operation)
//{
//
//}

void 	process(t_stack *stack1, t_stack *stack2)
{
	char *line;
	int operation;
	t_list *operation_list;

	(void)stack2;
	while (get_next_line(1, &line) != 0)
	{
		operation = get_operation(line);
		if (operation < 0 || operation > 11)
		{
			error_handler(1);
		}
		ft_lstadd_front(&operation_list, ft_lstnew((void *)(&operation)));
	}
	t_list *tmp = operation_list;
	printf("tut\n");
	while (tmp)
	{
		printf("oper = %d\n", (*(int *)(tmp->content)));
	}
//	do_operation(stack1, stack2, operation);
	if (is_sorted(stack1))
		ft_putstr_fd(GREEN_COLOR"OK"END_COLOR, 1);
	else
		ft_putstr_fd(RED_COLOR"KO"END_COLOR, 1);
}

int		main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;

	printf("hello!\n");
	if (argc != 1)
	{
		init(&stack1);
		init(&stack2);
		get_stack(stack1, argc, argv);
		process(stack1, stack2);

//	print_stack(stack);
	}
	return (0);
}



//int main()
//{
//	t_list *list;
//	for (int i = 0; i < 10; ++i) {
//		ft_lstadd_back(&list, ft_lstnew(&i));
//	}
//}