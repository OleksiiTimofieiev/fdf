/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:18:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 13:01:59 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	row(t_g **g, t_buf *buf, int i, int j)
{
	buf->x = (*g)->data[i][j].x * (*g)->step;
	buf->y = (*g)->data[i][j].y * (*g)->step +
	(*g)->data[i][j].z;
	buf->w = ((*g)->data[i][j + 1].x * (*g)->step)
	- ((*g)->data[i][j].x * (*g)->step);
	buf->h = ((*g)->data[i][j + 1].y * (*g)->step
	+ (*g)->data[i][j + 1].z) - ((*g)->data[i][j].y *
	(*g)->step + (*g)->data[i][j].z);
	buf->dx1 = 0;
	buf->dx2 = 0;
	buf->dy1 = 0;
	buf->dy2 = 0;
	buf->iterator = 0;
}

void	lin(t_g **g, t_buf *buf, int j, int i)
{
	buf->x = (*g)->data[j][i].x * (*g)->step;
	buf->y = (*g)->data[j][i].y * (*g)->step +
	(*g)->data[j][i].z;
	buf->w = ((*g)->data[j + 1][i].x * (*g)->step) -
	((*g)->data[j][i].x * (*g)->step);
	buf->h = ((*g)->data[j + 1][i].y * (*g)->step +
	(*g)->data[j + 1][i].z) - ((*g)->data[j][i].y *
	(*g)->step + (*g)->data[j][i].z);
	buf->dx1 = 0;
	buf->dx2 = 0;
	buf->dy1 = 0;
	buf->dy2 = 0;
	buf->iterator = 0;
}

void	set_deviation(t_buf *buf)
{
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

void	set_longest_shortest_numerator(t_buf *buf)
{
	buf->longest = abs(buf->w);
	buf->shortest = abs(buf->h);
	if (!(buf->longest > buf->shortest))
	{
		buf->longest = abs(buf->h);
		buf->shortest = abs(buf->w);
		if (buf->h < 0)
			buf->dy2 = -1;
		else if (buf->h > 0)
			buf->dy2 = 1;
		buf->dx2 = 0;
	}
	buf->numerator = buf->longest >> 1;
}

void	line(t_g **g, int i, int j, int type_of_vector)
{
	t_buf	buf;

	(type_of_vector == TYPE_V_ROW) ? row(g, &buf, i, j) : lin(g, &buf, j, i);
	set_deviation(&buf);
	set_longest_shortest_numerator(&buf);
	while (buf.iterator <= buf.longest)
	{
		mlx_pixel_put((*g)->mlx_ptr, (*g)->win_ptr, buf.x,
		buf.y, 0xFFFFFF); // TODO: color;
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
