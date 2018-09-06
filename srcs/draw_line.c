/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:18:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 22:43:02 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	row(t_g **g, t_buf *buf, int i, int j)
{
	buf->x = (*g)->data[i][j].x * (*g)->step + (*g)->correction_x;
	buf->y = ((*g)->data[i][j].y * (*g)->step +
	(*g)->data[i][j].z) + (*g)->correction_y;
	buf->w = ((*g)->data[i][j + 1].x * (*g)->step + (*g)->correction_x)
	- (buf->x);
	buf->h = ((*g)->data[i][j + 1].y * (*g)->step
	+ (*g)->data[i][j + 1].z + (*g)->correction_y) - (buf->y);
	buf->dx1 = 0;
	buf->dx2 = 0;
	buf->dy1 = 0;
	buf->dy2 = 0;
	buf->iterator = 0;
	buf->color = (*g)->data[i][j].color;
}

static void	lin(t_g **g, t_buf *buf, int j, int i)
{
	buf->x = (*g)->data[j][i].x * (*g)->step + (*g)->correction_x;
	buf->y = (*g)->data[j][i].y * (*g)->step +
	(*g)->data[j][i].z + (*g)->correction_y;
	buf->w = ((*g)->data[j + 1][i].x * (*g)->step + (*g)->correction_x) -
	(buf->x);
	buf->h = ((*g)->data[j + 1][i].y * (*g)->step +
	(*g)->data[j + 1][i].z + (*g)->correction_y) - (buf->y);
	buf->dx1 = 0;
	buf->dx2 = 0;
	buf->dy1 = 0;
	buf->dy2 = 0;
	buf->iterator = 0;
	buf->color = (*g)->color;
	buf->color = (*g)->data[j][i].color;
}

static void	set_deviation(t_buf *buf, int *c)
{
	*c = 0;
	if (buf->w < 0)
		buf->dx1 = -1;
	else if (buf->w > 0)
		buf->dx1 = 1;
	if (buf->h < 0)
		buf->dy1 = -1;
	else if (buf->h > 0)
		buf->dy1 = 1;
	if (buf->w < 0)
		buf->dx2 = -1;
	else if (buf->w > 0)
		buf->dx2 = 1;
}

static void	set_longest_shortest_numerator(t_buf *buf)
{
	buf->longest = fabs(buf->w);
	buf->shortest = fabs(buf->h);
	if (!(buf->longest > buf->shortest))
	{
		buf->longest = fabs(buf->h);
		buf->shortest = fabs(buf->w);
		if (buf->h < 0)
			buf->dy2 = -1;
		else if (buf->h > 0)
			buf->dy2 = 1;
		buf->dx2 = 0;
	}
	buf->numerator = buf->longest >> 1;
}

void		line(t_g **g, int i, int j, int type_of_vector)
{
	t_buf	buf;
	int		c;

	(type_of_vector == TYPE_V_ROW) ? row(g, &buf, i, j) : lin(g, &buf, j, i);
	set_deviation(&buf, &c);
	set_longest_shortest_numerator(&buf);
	while (buf.iterator <= buf.longest)
	{
		mlx_pixel_put((*g)->mlx_ptr, (*g)->win_ptr, buf.x,
		buf.y, buf.color + c);
		c += (*g)->gradient;
		buf.numerator += buf.shortest;
		if (!(buf.numerator < buf.longest))
		{
			buf.numerator -= buf.longest;
			buf.x += buf.dx1;
			buf.y += buf.dy1;
		}
		else
		{
			buf.x += buf.dx2;
			buf.y += buf.dy2;
		}
		buf.iterator++;
	}
}
