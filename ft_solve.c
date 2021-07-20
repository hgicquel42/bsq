/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abfall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:36:48 by abfall            #+#    #+#             */
/*   Updated: 2021/07/20 13:36:49 by abfall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_min3(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < c)
		return (b);
	else
		return (c);
	return (0);
}

int	ft_count(int **lines, int x, int y)
{
	int	top;
	int	left;
	int	topleft;

	left = lines[y][x - 1];
	top = lines[y - 1][x];
	topleft = lines[y - 1][x - 1];
	return (ft_min3(left, top, topleft) + 1);
}

t_point	ft_point(int x, int y, int v)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.v = v;
	return (point);
}

int	ft_solve(t_params *params, int **lines)
{
	int		x;
	int		y;
	t_point	max;

	max = ft_point(0, 0, 0);
	y = 1;
	while (y < params->size)
	{
		x = 1;
		while (x < params->length)
		{
			if (lines[y][x] == EMPTY)
				lines[y][x] = ft_count(lines, x, y);
			if (lines[y][x] > max.v)
				max = ft_point(x, y, lines[y][x]);
			x++;
		}
		y++;
	}
	ft_print(params, lines, max);
	return (1);
}
