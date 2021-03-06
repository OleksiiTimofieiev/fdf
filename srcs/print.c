/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:53:56 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 13:02:32 by otimofie         ###   ########.fr       */
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
			line(&g, i, j++, TYPE_V_ROW);
		i++;
	}
}

static void	print_column(t_g *g)
{
	int i;
	int j;
	int length;

	i = 0;
	j = 0;
	length = 0;
	while (g->data[length])
		length++;
	while (j < length - 1)
	{
		i = 0;
		while (g->data[j][i].x != INT_STOP)
			line(&g, i++, j, TYPE_V_LINE);
		j++;
	}
}

void		print(t_g *g)
{
	print_row(g);
	print_column(g);
}
