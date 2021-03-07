NAME = checker
#CC = /usr/bin/clang-10
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS_DIR = ./srcs/

INCLUDES   = ./includes/

LIBFT_DIR   = $(SRCS_DIR)libft/
CHECKER_DIR   = $(SRCS_DIR)checker/
STACK_DIR     = $(SRCS_DIR)stack/

SRCS_STACK = $(addprefix $(STACK_DIR), \
                clear.c print_stack.c stack.c stack_utils.c \
                sa_sb_ss.c pa_pb.c)

SRCS_CHECKER = $(addprefix $(CHECKER_DIR), \
                main.c get_stack.c error_handler.c)


OBJ_STACK = $(SRCS_STACK:.c=.o)

OBJ_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJS_CHECKER_PROGRAM = $(OBJ_STACK) $(OBJ_CHECKER)


all:$(NAME)

$(NAME): $(OBJS_CHECKER_PROGRAM)
	@make -C $(LIBFT_DIR)
	gcc $(CFLAGS) -I$(CHECKER_INCLUDES) $(OBJS_CHECKER_PROGRAM) $(LIBFT_DIR)/libft.a -o $(NAME)
	@echo Sources files compiled!


$(OBJ_CHECKER): %.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_STACK): %.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -I$(LIBFT_DIR) -c $< -o $@

%.o:%.c%$(INCLUDES)
	@$(CC) $(FLAGS) -o I$(INCLUDES)  $@ -c $<

clean:
	@rm -rf *.o
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(STACK_DIR)*.o $(CHECKER_DIR)*.o
	@echo Objects files deleted!

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

start:
	./minishell

norme:
	norminette $(SRCS) ./includes/*.h ./srcs/libft/*.c ./srcs/libft/*.h


re: fclean all

.PHONY: all objs clean fclean re