# Standard
NAME	=	philo

# Compiler and CFlags
CC		=	cc
CFLAGS		=	-Wall -Werror -Wextra 
RM		=	rm -f
THRDFLAG	=	-fsanitize=thread
MEMRYFLAG	=	-fsanitize=address

# Source files
SRCS	=		philo.c			\
			check_arguments.c	\
			threads.c		\
			handle_errors.c		\
			init.c			\
			routine_actions.c	\
			utils.c			\
			thread_utils.c		\

# Object files
OBJS	=	$(SRCS:.c=.o)

# Build rules
start:
		@make all

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	start all clean fclean re