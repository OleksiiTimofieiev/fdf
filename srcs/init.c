/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:49:35 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 11:28:07 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_g(t_g *g)
{
	g->data = NULL;
	g->parsed_data = NULL;
	g->mlx_ptr = NULL;
	g->win_ptr = NULL;
	g->step = STEP_BASE;
}
