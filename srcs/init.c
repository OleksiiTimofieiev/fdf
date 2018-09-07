/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:49:35 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/07 13:21:11 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_g(t_g *g, char **argv)
{
	g->data = NULL;
	g->parsed_data = transform_to_int(argv[0]);
	g->mlx_ptr = NULL;
	g->win_ptr = NULL;
	g->step = INIT_SCALE;
	g->color = INIT_COLOR;
	g->correction_x = INIT_CORRECTION_X;
	g->correction_y = INIT_CORRECTION_Y;
	g->corner = 0;
	g->gradient = -2.0;
	if (g->parsed_data)
	{
		// g->mlx_ptr = mlx_init();
		// g->win_ptr = mlx_new_window(g->mlx_ptr, MONITOR_WIDTH,
		// MONITOR_HEIGHT, "fdf");
		// mlx_string_put(g->mlx_ptr, g->win_ptr, 1100, 650, 0xFFFFFF,
		// "Please, push 'x' to continue.");

	}
	else
	{
		ft_putstr("Bad input.\n");
		exit(0);
	}
}

int		len_max(int **array)
{
	int i;
	int j;
	int len;
	int count;

	i = 0;
	j = 0;
	len = 0;
	count = 0;
	while (array[i])
	{
		j = 0;
		count = 0;
		while (array[i][j] != INT_STOP)
		{
			count++;
			j++;
		}
		len = (count > len) ? count : len;
		i++;
	}
	return (len);
}

int		size_double(int **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	check_line(char **line, int fd)
{
	if (!(*line))
	{
		close(fd);
		ft_putstr("Bad input.\n");
		exit(0);
	}
	else
		free(*line);
}

void	check_tmp(char **tmp, int fd)
{
	if (!(*tmp))
	{
		close(fd);
		ft_putstr("Bad input.\n");
		exit(0);
	}
}
