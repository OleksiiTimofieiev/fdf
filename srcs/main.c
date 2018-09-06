/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 10:45:34 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO: 1 dot; // broz to all sides;
// TODO: esc -> exit 0
// TODO: defines for colors;
// TODO: сдвиг;
// TODO: https://www.tutorialspoint.com/c_standard_library/math_h.htm
// TODO: mo

void line(int x, int y, int x2, int y2, void **mlx_ptr, void **win_ptr) // TODO:pass data[i][j];
{
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
		mlx_pixel_put(*mlx_ptr, *win_ptr, x, y, 0xFFFFFF);
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

void print_row(t_general *general)
{
	int i = 0;
	int j = 0;

	// TODO: intermidiate struct will be passed;

	while (general->data[i])
	{
		j = 0;

		while (general->data[i][j + 1].x != INT_STOP)
		{
			line((general->data[i][j].x) * general->step, (general->data[i][j].y) * general->step + general->data[i][j].z, (general->data[i][j + 1].x) * general->step,
			 (general->data[i][j + 1].y) * general->step + general->data[i][j + 1].z, &general->mlx_ptr, &general->win_ptr);
			j++;
		}
		i++;
	}

}

void print_column(t_general *general)
{
	int j = 0;
	int i = 0;

	int length = 0;
	while(general->data[length])
		length++;
	
	while(j < length - 1)
	{
		i = 0;
		while (general->data[j][i].x != INT_STOP)
		{
			line((general->data[j][i].x) * general->step, (general->data[j][i].y) * general->step + general->data[j][i].z, (general->data[j + 1][i].x) * general->step,
			 (general->data[j + 1][i].y) * general->step + general->data[j + 1][i].z, &general->mlx_ptr, &general->win_ptr);
			i++;
		}
		j++;
	}
}

void init(t_general *general)
{
	general->data = NULL;
	general->parsed_data = NULL;
	general->mlx_ptr = NULL;
	general->win_ptr = NULL;
	general->step = STEP_BASE;
}

	int main(int argc, char **argv)
{
	t_general	general;
	
	init(&general);
	if (argc == 2)
		(!(general.parsed_data = transform_to_int(argv[1]))) ? ft_putstr("Invalid data in the file.\n") : 0;
	(general.parsed_data) ? general.data = fill_the_initial_matrix(general.parsed_data) : exit(0); // TODO: func for exit;
	general.mlx_ptr = mlx_init();
	general.win_ptr = mlx_new_window(general.mlx_ptr, 5120, 2880, "fdf");

	
	print_row(&general);
	print_column(&general);



	
	mlx_loop(general.mlx_ptr);



	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_new_window - clear(for refresh) - destroy(create bigger window),

	system("leaks -q fdf");

	return (0);
}
