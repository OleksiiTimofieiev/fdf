/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:53:56 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 12:37:38 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	print_row(t_g *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g->data[i])
	{
		j = 0;
		while (g->data[i][j + 1].x != INT_STOP)
			line(&g, i, j++, ROW);
		i++;
	}
}

// static void	print_column(t_g *g)
// {
// 	int i;
// 	int j;
// 	int length;

// 	i = 0;
// 	j = 0;
// 	length = 0;
// 	while (g->data[length])
// 		length++;
// 	while (j < length - 1)
// 	{
// 		i = 0;
// 		while (g->data[j][i].x != INT_STOP)
// 		{
// 			line(g->data[j][i].x * g->step,
// 			g->data[j][i].y * g->step + g->data[j][i].z,
// 			g->data[j + 1][i].x * g->step,
// 			g->data[j + 1][i].y * g->step
// 			+ g->data[j + 1][i].z,
// 			&g->mlx_ptr, &g->win_ptr);
// 			i++;
// 		}
// 		j++;
// 	}
// }

void		print(t_g *g)
{
	print_row(g);
	// print_column(g);
}
