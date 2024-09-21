# Standard
NAME	=	philo

# Compiler and CFlags
CC		=	cc -g
CFLAGS		=	-Wall -Werror -Wextra 
RM		=	rm -f
THRDFLAG	=	-fsanitize=thread
MEMRYFLAG	=	-fsanitize=address

# Extras
FT_PRINTF	=	./ft_printf/ft_printf_stder.a

# Source files
SRCS	=		philo.c			\
			check_arguments.c	\
			threads.c		\
			handle_errors.c		\
			init.c			\
			routine_actions.c	\
			utils.c			\
			thread_utils.c		\
			monitor.c		\
			utils_pt2.c		\

# Object files
OBJS	=	$(SRCS:.c=.o)

# Build rules
start:
		@make all

all:	$(NAME)

$(FT_PRINTF):
	@make -C ./ft_printf

$(NAME):	$(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) -o $(NAME)

clean:
	rm -rf $(OBJS)
	@make clean -C ./ft_printf

fclean:		clean
	rm -f $(NAME)
	@rm $(FT_PRINTF)

re:	fclean all

.PHONY:	start all clean fclean re
