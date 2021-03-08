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
	if (operation >= RA && operation <= RR)
		ra_rb_rr(stack1, stack2, operation);
	if (operation >= RRA && operation <= RRR)
		rra_rrb_rrr(stack1, stack2, operation);
}

void clear_term()
{
	write(1, "\x1B[2J\x1B[H", 13);
}

void 		print_operation(int operation)
{
	ft_putstr_fd(RED_COLOR"Operation : ", 1);
	if (operation == SA)
		ft_putendl_fd("SA"END_COLOR, 1);
	if (operation == SB)
		ft_putendl_fd("SB"END_COLOR, 1);
	if (operation == SS)
		ft_putendl_fd("SS"END_COLOR, 1);
	if (operation == PA)
		ft_putendl_fd("PA"END_COLOR, 1);
	if (operation == PB)
		ft_putendl_fd("PB"END_COLOR, 1);
	if (operation == RA)
		ft_putendl_fd("RA"END_COLOR, 1);
	if (operation == RB)
		ft_putendl_fd("RB"END_COLOR, 1);
	if (operation == RR)
		ft_putendl_fd("RR"END_COLOR, 1);
	if (operation == RRA)
		ft_putendl_fd("RRA"END_COLOR, 1);
	if (operation == RRB)
		ft_putendl_fd("RRB"END_COLOR, 1);
	if (operation == RRR)
		ft_putendl_fd("RRR"END_COLOR, 1);


}

void do_operations(t_stack *stack1, t_stack *stack2, t_list *operations)
{
	clear_term();
	while (operations)
	{
		print_stacks(stack1, stack2);
		sleep(3);
		clear_term();
		print_operation((*(int *)operations->content));
		do_operation(stack1, stack2, (*(int *)(operations->content)));
		operations = operations->next;
	}
	print_stacks(stack1, stack2);
	sleep(1);
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
	if (is_sorted(stack1) && stack1->size_ == stack1->size_started)
		ft_putstr_fd(GREEN_COLOR"OK\n"END_COLOR, 1);
	else
		ft_putstr_fd(RED_COLOR"KO\n"END_COLOR, 1);
}

int		main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;
	t_features features;

	if (argc != 1)
	{
		init(&stack1);
		init(&stack2);
		get_stack(stack1, argc, argv, &features);
		process(stack1, stack2);
//		clear(&stack1);
//		clear(&stack2);
	}
	return (0);
}
