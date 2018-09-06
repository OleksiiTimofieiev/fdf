/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:18:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 11:55:38 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO: type of x and y;

// typedef	struct	s_buf
// {
// 	int			w;
// 	int			h;
// 	int			dx1;
// 	int			dy1; 
// 	int			dx2;
// 	int			dy2;
// 	int			longest;
// 	int			shortest;
// 	int			numerator;
// }				t_buf;

void	init_data_for_drawing(t_g ** g, t_buf *buf, int i, int j)
{
	buf->x = (*g)->data[i][j].x * (*g)->step;
	buf->y = (*g)->data[i][j].y * (*g)->step + (*g)->data[i][j].z;
	buf->w = ((*g)->data[i][j + 1].x * (*g)->step) - ((*g)->data[i][j].x * (*g)->step);
	buf->h = ((*g)->data[i][j + 1].y * (*g)->step + (*g)->data[i][j + 1].z) - ((*g)->data[i][j].y * (*g)->step + (*g)->data[i][j].z);
	
}

void	line(t_g ** g, int i, int j)
{	
	t_buf	buf;

	init_data_for_drawing(g, &buf, i, j);

	int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
	
	if (buf.w < 0)
		dx1 = -1;
	else if (buf.w > 0)
		dx1 = 1;
	if (buf.h < 0)
		dy1 = -1;
	else if (buf.h > 0)
		dy1 = 1;
	if (buf.w < 0)
		dx2 = -1;
	else if (buf.w > 0)
		dx2 = 1;
		
	int longest = abs(buf.w);
	int shortest = abs(buf.h);
	
	if (!(longest > shortest))
	{
		longest = abs(buf.h);
		shortest = abs(buf.w);
		if (buf.h < 0)
			dy2 = -1;
		else if (buf.h > 0)
			dy2 = 1;
		dx2 = 0;
	}

	int numerator = longest >> 1;

	for (int i = 0; i <= longest; i++)
	{
		mlx_pixel_put((*g)->mlx_ptr, (*g)->win_ptr, buf.x, buf.y, 0xFFFFFF);
		numerator += shortest;
		if (!(numerator < longest))
		{
			numerator -= longest;
			buf.x += dx1;
			buf.y += dy1;
		}
		else
		{
			buf.x += dx2;
			buf.y += dy2;
		}
	}
}