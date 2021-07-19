#include "ft_bsq.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putout(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_puterr(char *s)
{
	write(2, s, ft_strlen(s));
}
