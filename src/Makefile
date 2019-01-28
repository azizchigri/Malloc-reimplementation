##
## EPITECH PROJECT, 2018
## rush3
## File description:
## Mafefile to use malloc project
##

CC	=	gcc

RM	=	rm -f

NAME	=	../libmy_malloc.so

SRCS	=	malloc_implementation.c	\
			manage_list.c			\
			manage_block.c			\
			free.c					\
			calloc.c				\
			realloc.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-I../include -W -Wall -Wextra -Werror -fPIC -lpthread -Wpadded

LDFLAGS	+=	-shared

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -c $(CFLAGS) $(SRCS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean allME1) $(OBJS1) $(CFLAGS)
	./$(NAME1)

.PHONY: all clean fclean re
