/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:53:56 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 11:10:54 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	print_row(t_general *general)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (general->data[i])
	{
		j = 0;
		while (general->data[i][j + 1].x != INT_STOP)
		{
			line(general->data[i][j].x * general->step, general->data[i][j].y *
			general->step + general->data[i][j].z, general->data[i][j + 1].x
			* general->step, general->data[i][j + 1].y * general->step
			+ general->data[i][j + 1].z, &general->mlx_ptr,
			&general->win_ptr);
			j++;
		}
		i++;
	}
}

static void	print_column(t_general *general)
{
	int i;
	int j;
	int length;

	i = 0;
	j = 0;
	length = 0;
	while (general->data[length])
		length++;
	while (j < length - 1)
	{
		i = 0;
		while (general->data[j][i].x != INT_STOP)
		{
			line(general->data[j][i].x * general->step,
			general->data[j][i].y * general->step + general->data[j][i].z,
			general->data[j + 1][i].x * general->step,
			general->data[j + 1][i].y * general->step
			+ general->data[j + 1][i].z,
			&general->mlx_ptr, &general->win_ptr);
			i++;
		}
		j++;
	}
}

void		print(t_general *general)
{
	print_row(general);
	print_column(general);
}
