/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:13:13 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 18:47:52 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	navigation(t_g **g)
{
	mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 30, 35, 0x008000,
	"Menu:");
	mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 30, 65, 0xFFFFFF,
	"Zoom in <=> '+'");
	mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 30, 95, 0xFFFFFF,
	"Zoom out <=> '-'");
	mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 30, 125, 0xFFFFFF,
	"BLUE <=> 'q'");
	mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 30, 155, 0xFFFFFF,
	"YELLOW <=> 'w'");
	mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 30, 185, 0xFFFFFF,
	"MAGENTA <=> 'e'");
	mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 30, 215, 0xFFFFFF,
	"GREEN <=> 'r'");
	mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 30, 245, 0xFFFFFF,
	"ROTATION <=> 'SPACE'");
	mlx_string_put((*g)->mlx_ptr, (*g)->win_ptr, 30, 275, 0xFFFFFF,
	"ROTATION CLOCKWISE <=> 'ENTER'");
}

static	void	change_color(int key, t_g **g)
{
	if (key == 12)
		(*g)->color = BLUE_COLOR;
	else if (key == 13)
		(*g)->color = YELLOW_COLOR;
	else if (key == 14)
		(*g)->color = MAGENTA_COLOR;
	else if (key == 15)
		(*g)->color = GREEN_COLOR;
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
	navigation(&g);
	print(g);
	return (0);
}
