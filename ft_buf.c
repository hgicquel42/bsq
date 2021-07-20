/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abfall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:36:05 by abfall            #+#    #+#             */
/*   Updated: 2021/07/20 13:36:06 by abfall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	**ft_alloc(t_params *params)
{
	int	i;
	int	**array;

	array = malloc(params->size * params->length * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (i < params->size)
		array[i++] = 0;
	return (array);
}

int	*ft_parse(t_params *params, char *buffer)
{
	int	i;
	int	*array;

	array = malloc(params->length * sizeof(int));
	if (!array)
		return (0);
	i = 0;
	while (i < params->length)
	{
		if (buffer[i] == params->empty)
			array[i] = EMPTY;
		else if (buffer[i] == params->obstacle)
			array[i] = OBSTACLE;
		else
		{
			free(array);
			return (0);
		}
		i++;
	}
	return (array);
}
