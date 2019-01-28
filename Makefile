##
## EPITECH PROJECT, 2018
## rush3
## File description:
## Mafefile to use malloc project
##

CC	=	gcc

RM	=	rm -f

NAME	=	test

SRCS	=	src/malloc_implementation.c			\
			src/manage_list.c					\
			src/manage_block.c					\
			src/free.c							\
			src/calloc.c						\
			src/realloc.c						\
			tests/test_calloc.c					\
			tests/test_list.c					\
			tests/test_block.c					\
			tests/test_malloc.c					\
			tests/test_on_system.c				\
			tests/test_realloc.c				\
			tests/test_free.c					\
			tests/test.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Iinclude -W -Wall -Wextra -Werror -fPIC -lpthread -Wpadded

LDFLAGS	+=	-shared

all:	$(NAME)

$(NAME):
	make -C src

clean:
	make -C src clean
	$(RM) $(OBJS)

fclean:	clean
	make -C src fclean
	$(RM) $(NAME)

re:	fclean all

tests_run: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	./$(NAME)

.PHONY: all clean fclean re tests_run
