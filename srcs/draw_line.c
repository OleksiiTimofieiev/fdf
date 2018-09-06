/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:18:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 11:39:14 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void line(t_g ** g, int i, int j) // TODO:pass data[i][j];
{	

	int x = (*g)->data[i][j].x * (*g)->step;
	int y = (*g)->data[i][j].y * (*g)->step + (*g)->data[i][j].z;
	int x2 = (*g)->data[i][j + 1].x * (*g)->step;
	int y2 = (*g)->data[i][j + 1].y * (*g)->step + (*g)->data[i][j + 1].z;




	
	int w = x2 - x;
	int h = y2 - y;
	int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
	if (w < 0)
		dx1 = -1;
	else if (w > 0)
		dx1 = 1;
	if (h < 0)
		dy1 = -1;
	else if (h > 0)
		dy1 = 1;
	if (w < 0)
		dx2 = -1;
	else if (w > 0)
		dx2 = 1;
	int longest = abs(w);
	int shortest = abs(h);
	
	if (!(longest > shortest))
	{
		longest = abs(h);
		shortest = abs(w);
		if (h < 0)
			dy2 = -1;
		else if (h > 0)
			dy2 = 1;
		dx2 = 0;
	}

	int numerator = longest >> 1;

	for (int i = 0; i <= longest; i++)
	{
		mlx_pixel_put((*g)->mlx_ptr, (*g)->win_ptr, x, y, 0xFFFFFF);
		numerator += shortest;
		if (!(numerator < longest))
		{
			numerator -= longest;
			x += dx1;
			y += dy1;
		}
		else
		{
			x += dx2;
			y += dy2;
		}
	}
}