/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abfall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 13:35:58 by abfall            #+#    #+#             */
/*   Updated: 2021/07/20 13:36:00 by abfall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define LINE 1024

# define EMPTY 1
# define OBSTACLE 0

typedef struct s_params
{
	int		size;
	int		length;
	char	empty;
	char	obstacle;
	char	full;
}	t_params;

typedef struct s_point
{
	int	v;
	int	x;
	int	y;
}	t_point;

int			ft_strlen(char *s);

void		ft_putchar(char c);

void		ft_putout(char *s);

void		ft_puterr(char *s);

int			ft_is_printable(char c);

int			ft_is_number(char c);

int			**ft_alloc(t_params *params);

int			*ft_parse(t_params *params, char *buffer);

t_params	*ft_read_header(int file);

int			**ft_read_lines(int file, t_params *params);

int			ft_solve(t_params *params, int **lines);

void		ft_print(t_params *params, int **lines, t_point max);

#endif
