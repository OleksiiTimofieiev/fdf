/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/05 16:01:08 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO: 1 dot; // broz to all sides;
// TODO: esc -> exit 0
// TODO: defines for colors;
// TODO: сдвиг;

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

void print_row(t_coord **data, void **mlx_ptr, void **win_ptr)
{
	int i = 0;
	int j = 0;

	// TODO: intermidiate struct will be passed;

	while (data[i])
	{
		j = 0;

		while (data[i][j + 1].x != INT_STOP)
		{
			line((data[i][j].x) * STEP, (data[i][j].y + data[i][j].z) * STEP, (data[i][j + 1].x) * STEP, (data[i][j + 1].y + data[i][j + 1].z) * STEP, mlx_ptr, win_ptr);
			j++;
		}
		i++;
	}

}

void print_column(t_coord **data, void **mlx_ptr, void **win_ptr)
{
	int j = 0;
	int i = 0;

	int length = 0;
	while(data[length])
		length++;
	
	while(j < length - 1)
	{
		i = 0;
		while (data[j][i].x != INT_STOP)
		{
			line((data[j][i].x) * STEP, (data[j][i].y + data[j][i].z) * STEP, (data[j + 1][i].x) * STEP, (data[j + 1][i].y + data[j + 1][i].z) * STEP, mlx_ptr, win_ptr);
			i++;
		}
		j++;
	}
}

int		main(int argc, char **argv)
{
	int			**parsed_data;
	t_coord		**data;
	void		*mlx_ptr = NULL;
	void		*win_ptr = NULL;
	
	data = NULL;
	parsed_data = NULL;
	if (argc == 2)
		(!(parsed_data = transform_to_int(argv[1]))) ? ft_putstr("Invalid data in the file.\n") : 0;
	(parsed_data) ? data = fill_the_initial_matrix(parsed_data) : exit(0);

	
	mlx_ptr = mlx_init();
	// mlx_clear_window(mlx_ptr, win_ptr);
	win_ptr = mlx_new_window(mlx_ptr, 5120, 2880, "fdf");
	// print_row(data, &mlx_ptr, &win_ptr);
	// print_column(data, &mlx_ptr, &win_ptr);

	line(5 * STEP, 5 * STEP, 10 * STEP, 10 * STEP, &mlx_ptr, &win_ptr);
	line(5 * STEP, 5 * STEP, 10 * STEP, 5 * STEP, &mlx_ptr, &win_ptr);
	line(5 * STEP, 5 * STEP, 5 * STEP, 10 * STEP, &mlx_ptr, &win_ptr);
	line(5 * STEP, 5 * STEP, 5 * STEP, 10 * STEP, &mlx_ptr, &win_ptr);


	mlx_loop(mlx_ptr);

	// mlx_new_window - clear(for refresh) - destroy(create bigger window),

	system("leaks -q fdf");

	return (0);
}
