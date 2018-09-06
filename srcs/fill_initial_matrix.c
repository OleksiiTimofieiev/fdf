/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_initial_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:07:43 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 23:06:46 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		rows(int **parsed_data)
{
	int i;

	i = 0;
	while (parsed_data[i])
		i++;
	return (i);
}

static int		size_row(int *parsed_data)
{
	int i;

	i = 0;
	while (parsed_data[i] != INT_STOP)
		i++;
	return (i);
}

t_coord			**fill_the_initial_matrix(int **parsed_data)
{
	t_coord	**res;
	int		i;
	int		j;

	i = 0;
	if (!(res = (t_coord **)malloc(sizeof(t_coord *) * rows(parsed_data) + 1)))
		return (NULL);
	while (i < rows(parsed_data))
	{
		if (!(res[i] = (t_coord *)malloc(sizeof(t_coord)
			* size_row(parsed_data[i]) + 1)))
			return (NULL);
		j = 0;
		while (j < size_row(parsed_data[i]))
		{
			res[i][j].x = j;
			res[i][j].y = i;
			res[i][j].z = parsed_data[i][j];
			res[i][j++].color = 0xFFFFFF ;
		}
		res[i][j].x = INT_STOP;
		i++;
	}
	res[i] = NULL;
	return (res);
}
