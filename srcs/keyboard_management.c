/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:13:13 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 17:16:25 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	change_color(int key, t_g **g)
{
	if (key == 12)
		(*g)->color = BLUE_COLOR;
	else if (key == 13)
		(*g)->color = YELLOW_COLOR;
	else if (key == 14)
		(*g)->color = MAGENTA_COLOR;
	else if (key == 15)
		(*g)->color = INIT_COLOR;
}

static	void	change_position(int key, t_g **g)
{
	if (key == 126)
		(*g)->correction_y -= MOV_SCALE;
	else if (key == 125)
		(*g)->correction_y += MOV_SCALE;
	else if (key == 123)
		(*g)->correction_x -= MOV_SCALE;
	else if (key == 124)
		(*g)->correction_x += MOV_SCALE;
}

static	void	change_scale(int key, t_g **g)
{
	if (key == 69)
		(*g)->step += SCALE;
	else if (key == 78)
		(*g)->step -= SCALE;
}

int				deal_with_keyboard(int key, t_g *g)
{
	if (key == 53)
	{
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		exit(1);
		return (0);
	}
	change_color(key, &g);
	change_position(key, &g);
	change_scale(key, &g);
	rotate(key, &g);
	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	print(g);
	return (0);
}
