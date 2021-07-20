/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abfall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:36:41 by abfall            #+#    #+#             */
/*   Updated: 2021/07/20 13:36:42 by abfall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_check(int x, int y, t_point max)
{
	if (x > max.x)
		return (0);
	if (x < max.x - (max.v - 1))
		return (0);
	if (y > max.y)
		return (0);
	if (y < max.y - (max.v - 1))
		return (0);
	return (1);
}

void	ft_print(t_params *params, int **lines, t_point max)
{
	int		x;
	int		y;

	y = 0;
	while (y < params->size)
	{
		x = 0;
		while (x < params->length)
		{
			if (lines[y][x] == OBSTACLE)
				ft_putchar(params->obstacle);
			else if (ft_check(x, y, max))
				ft_putchar(params->full);
			else
				ft_putchar(params->empty);
			x++;
		}
		ft_putout("\n");
		y++;
	}
}
