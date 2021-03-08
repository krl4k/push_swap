#ifndef CHECKER_H
#define CHECKER_H

#include "libft.h"
#include "stack.h"
#ifndef DEBUG
#define DEBUG 1
#endif

#define RED_COLOR "[1;31m"
#define GREEN_COLOR "[1;32m"
#define BLUE_COLOR "[1;34m"
#define BG_RED_COLOR "[1;41m"
#define BG_BLUE_COLOR "[1;44m"

#define END_COLOR "\033[0m"


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


typedef struct s_features
{
	int debug;
	int last_operation;
}				t_features;

/*
** @param argc
** @param argv
** @return array of numbers received from argv
*/

int		*get_stack_in_array(int ac, char **av, int *size, int i);

/*
** @param1  stack
** @param2  array
*/

void array_to_stack(t_stack *stack, int *stack_array, int count);

void check_number(const char *n);


void get_stack(t_stack *stack1, int argc, char **argv, t_features *features);



int is_number(const char *str);


void error_handler(int error_code);




#endif