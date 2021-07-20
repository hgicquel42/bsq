NAME = bsq

FILES = \
	ft_main.c \
	ft_out.c \
	ft_parse.c \
	ft_solve.c \
	ft_char.c \
	ft_buf.c \
	ft_print.c

OBJS = $(FILES:.c=.o)

all: ${NAME}

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	gcc -Wall -Wextra -Werror ${OBJS} -o ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

test: ${NAME}
	perl gen.pl 50 50 1 > test
	./bsq test

.PHONY: all test clean