/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:49:35 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 18:25:16 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_g(t_g *g)
{
	g->data = NULL;
	g->parsed_data = NULL;
	g->mlx_ptr = NULL;
	g->win_ptr = NULL;
	g->step = INIT_SCALE;
	g->color = INIT_COLOR;
	g->correction_x = INIT_CORRECTION_X;
	g->correction_y = INIT_CORRECTION_Y;
	g->corner = 0;
	g->gradient = -2.0;	
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, MONITOR_WIDTH,
	MONITOR_HEIGHT, "fdf");
	mlx_string_put(g->mlx_ptr, g->win_ptr, 1100, 650, 0xFFFFFF, "Please, push 'x' to continue.");
}
