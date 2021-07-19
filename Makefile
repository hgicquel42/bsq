NAME = bsq

FILES = \
	ft_main.c \
	ft_out.c \
	ft_parse.c \
	ft_solve.c \
	ft_char.c \
	ft_buf.c \
	ft_print.c

all: ${NAME}

${NAME}:
	gcc -Wall -Wextra -Werror ${FILES} -o ${NAME}

nowarning:
	gcc ${FILES} -o ${NAME}

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

ren: fclean nowarning