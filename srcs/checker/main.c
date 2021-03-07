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

void do_operation(t_stack *stack1, t_stack *stack2, int operation)
{
	if (operation >= SA && operation <= SS)
		sa_sb_ss(stack1, stack2, operation);
	if (operation >= PA && operation <= PB)
		pa_pb(stack1, stack2, operation);
}

void do_operations(t_stack *stack1, t_stack *stack2, t_list *operations)
{
	while (operations)
	{
		print_stacks(stack1, stack2);
		sleep(1);
//		int cl = stack1->size_ > stack2->size_ ? stack1->size_ : stack2->size_;
//		for (int i = 0; i < cl; ++i)
//		{
//			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
//			printf("\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r");
//			printf("                ");
//			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
//			printf("\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r");
//		}
		do_operation(stack1, stack2, (*(int *)(operations->content)));
		operations = operations->next;
	}
	print_stacks(stack1, stack2);
	sleep(1);
//	int cl = stack1->size_ > stack2->size_ ? stack1->size_ : stack2->size_;
//	for (int i = 0; i < cl; ++i)
//	{
//		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
//		printf("                ");
//		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
//	}
}

void 	process(t_stack *stack1, t_stack *stack2)
{
	char *line;
	int *operation;
	t_list *operation_list;

	operation = NULL;
	operation_list = NULL;
	while (get_next_line(1, &line) != 0)
	{
		operation = (int *)malloc(sizeof(int));
		*operation = get_operation(line);
		if (*operation < 0 || *operation > 11)
			error_handler(1);
		ft_lstadd_back(&operation_list, ft_lstnew((int *)(operation)));
	}
	do_operations(stack1, stack2, operation_list);
//	printf("stack_size_ %d, stack_started_size %d\n", stack1->size_, stack1->size_started);
	if (is_sorted(stack1) && stack1->size_ == stack1->size_started)
		ft_putstr_fd(GREEN_COLOR"OK\n"END_COLOR, 1);
	else
		ft_putstr_fd(RED_COLOR"KO\n"END_COLOR, 1);
}

int		main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;

	if (argc != 1)
	{
		init(&stack1);
		init(&stack2);
		get_stack(stack1, argc, argv);
		process(stack1, stack2);
//		print_stack(stack1);
//		clear(&stack1);
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