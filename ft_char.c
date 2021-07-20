#include "ft_bsq.h"

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}
