NAME	= ft_printf_stder.a

CC		= cc
CFALGS	= -Wall -Werror -Wextra
ARFLAGS	= rcs
RM		= rm -rf

SRC		= 	ft_createptr\
			ft_getdigits\
			ft_htoa\
			ft_bightoa\
			ft_itoa\
			ft_printchar\
			ft_printf\
			ft_printhex\
			ft_printbighex\
			ft_printnbr\
			ft_printpercent\
			ft_printptr\
			ft_printstr\
			ft_strlen\
			ft_printunsigned\
			ft_putunsigned\

SRCS	= 	$(addsuffix .c, $(SRC))

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		ar $(ARFLAGS) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: fclean all
