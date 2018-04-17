##
## EPITECH PROJECT, 2017
## 
## File description:
## Makefile my_hunter
##

CC	=	gcc

NAME	=	my_hunter

RM	=	rm -f

SRC	=	hunter.c	\
		fonc.c		\
		calls.c		\

OBJS	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lc_graph_prog_full

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all

.PHONY:	all clean fclean re
