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

nowarning:
	gcc ${FILES} -o ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

ren: fclean nowarning
