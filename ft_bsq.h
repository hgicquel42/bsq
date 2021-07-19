#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define LINE 1024

# define EMPTY 0
# define OBSTACLE 1
# define FULL 2

typedef struct s_params
{
	int		size;
	int		length;
	char	empty;
	char	obstacle;
	char	full;
}	t_params;

int			ft_strlen(char *s);

void		ft_putout(char *s);

void		ft_puterr(char *s);

int			ft_is_number(char c);

int			**ft_alloc(t_params *params);

int			*ft_parse(t_params *params, char *buffer);

t_params	*ft_read_header(int file);

int			**ft_read_lines(int file, t_params *params);

int			ft_solve(t_params *params, int **lines);

#endif