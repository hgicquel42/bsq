/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abfall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:36:14 by abfall            #+#    #+#             */
/*   Updated: 2021/07/20 13:36:15 by abfall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_error(void)
{
	ft_puterr("map error\n");
	return (0);
}

int	ft_read_file(int file)
{
	t_params	*params;
	int			**lines;

	params = ft_read_header(file);
	if (params)
		lines = ft_read_lines(file, params);
	else
		lines = 0;
	close(file);
	if (lines)
		return (ft_solve(params, lines));
	return (0);
}

int	ft_read_arg(char *arg, int multiple)
{
	int	file;

	if (multiple)
		ft_putout("\n");
	file = open(arg, O_RDONLY);
	if (file == -1)
		return (ft_error());
	if (!ft_read_file(file))
		return (ft_error());
	return (1);
}

int	main(int argc, char **argv)
{
	int	index;
	int	error;

	if (argc == 1 && !ft_read_file(0))
		return (!ft_error());
	if (argc == 2)
		return (!ft_read_arg(argv[1], 0));
	index = 1;
	error = 0;
	while (index < argc)
		error |= !ft_read_arg(argv[index], index > 1), index++;
	return (error);
}
