/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:08:56 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/08 11:05:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	rotate_x(t_g *g, double corner)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g->data[i])
	{
		j = 0;
		while (g->data[i][j].x != INT_STOP)
		{
			g->data[i][j].x = g->data[i][j].x;
			g->data[i][j].y = g->data[i][j].y * cos(corner) +
			g->data[i][j].z * sin(corner);
			g->data[i][j].z = (g->data[i][j].y * sin(corner)) * -1 +
			g->data[i][j].z * cos(corner);
			j++;
		}
		i++;
	}
}

static	void	rotate_y(t_g *g, double corner)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g->data[i])
	{
		j = 0;
		while (g->data[i][j].x != INT_STOP)
		{
			g->data[i][j].y = g->data[i][j].y;
			g->data[i][j].x = g->data[i][j].x * cos(corner) +
			g->data[i][j].z * sin(corner);
			g->data[i][j].z = g->data[i][j].x * sin(corner) * -1 +
			g->data[i][j].z * cos(corner);
			j++;
		}
		i++;
	}
}

static	void	rotate_z(t_g *g, double corner)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g->data[i])
	{
		j = 0;
		while (g->data[i][j].x != INT_STOP)
		{
			g->data[i][j].z = g->data[i][j].z;
			g->data[i][j].x = g->data[i][j].x * cos(corner) -
			g->data[i][j].y * sin(corner);
			g->data[i][j].y = g->data[i][j].x * sin(corner) +
			g->data[i][j].y * cos(corner);
			j++;
		}
		i++;
	}
}

void			rotate(int key, t_g **g)
{
	double buf;

	buf = 0;
	if (key == 49)
		buf = 0.05;
	else if (key == 36)
		buf = -0.05;
	rotate_x(*g, buf);
	rotate_y(*g, buf);
	rotate_z(*g, buf);
}
