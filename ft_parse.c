#include "ft_bsq.h"

int	ft_read_line(int file, char *buffer, int *offset)
{
	*offset = 0;
	while (read(file, &buffer[*offset], 1))
	{
		if (*offset == LINE)
			return (0);
		if (buffer[*offset] == '\n')
			break ;
		(*offset)++;
	}
	return (1);
}

t_params	*ft_parse_header(char *buffer, int offset)
{
	int			i;
	t_params	*params;

	i = 0;
	params = malloc(sizeof(t_params));
	if (!params)
		return (0);
	params->size = 0;
	params->length = 0;
	while (i < (offset - 3) && ft_is_number(buffer[i]))
		params->size = (params->size * 10) + (buffer[i++] - '0');
	params->empty = buffer[i++];
	params->obstacle = buffer[i++];
	params->full = buffer[i++];
	if (i != offset)
		return (0);
	return (params);
}

t_params	*ft_read_header(int file)
{
	char	buffer[LINE];
	int		offset;

	offset = 0;
	if (!ft_read_line(file, buffer, &offset))
		return (0);
	return (ft_parse_header(buffer, offset));
}

int	**ft_read_lines(int file, t_params *params)
{
	int		line;
	int		offset;
	char	buffer[LINE];
	int		**lines;

	line = 0;
	lines = 0;
	while (line < params->size)
	{
		if (!ft_read_line(file, buffer, &offset))
			return (0);
		if (!params->length)
			params->length = offset;
		if (!offset || offset != params->length)
			return (0);
		if (!lines)
			lines = ft_alloc(params);
		if (!lines)
			return (0);
		lines[line] = ft_parse(params, buffer);
		if (!lines[line])
			return (0);
		line++;
	}
	return (lines);
}
