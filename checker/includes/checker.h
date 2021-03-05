#ifndef CHECKER_H
#define CHECKER_H

#include "colors.h"
#include "libft.h"
#include "stack.h"
#ifndef DEBUG
#define DEBUG 1
#endif

#define SA 1
#define SB 2
#define SS 3
#define PA 4
#define PB 5
#define RA 6
#define RB 7
#define RR 8
#define RRA 9
#define RRB 10
#define RRR 11


/*
** @param argc
** @param argv
** @return array of numbers received from argv
*/

int		*get_stack_in_array(int ac, char **av);

/*
** @param1  stack
** @param2  array
*/

void array_to_stack(t_stack *stack, int *stack_array, int count);

void get_stack(t_stack *stack1, int argc, char **argv);


int is_number(const char *str);


void error_handler(int error_code);


#endif