/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/05 14:07:45 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO: 1 dot; // broz to all sides;
// TODO: esc -> exit 0
// TODO: defines for colors;
// TODO: сдвиг;

void line(int x, int y, int x2, int y2, void **mlx_ptr, void **win_ptr)
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

	while (data[i])
	{
		j = 0;

		while (data[i][j + 1].x != INT_STOP)
		{
			line((data[i][j].x ) * 10, (data[i][j].y ) * 10, (data[i][j + 1].x ) * 10, (data[i][j + 1].y ) * 10, mlx_ptr, win_ptr);
			j++;
		}
		i++;
	}

}



int		main(int argc, char **argv)
{
	int			**parsed_data;
	t_coord		**data;
	void		*mlx_ptr;
	void		*win_ptr;
	
	data = NULL;
	parsed_data = NULL;
	if (argc == 2)
		(!(parsed_data = transform_to_int(argv[1]))) ? ft_putstr("Invalid data in the file.\n") : 0;
	(parsed_data) ? data = fill_the_initial_matrix(parsed_data) : exit(0);
	int i = 0;
	int j = 0;

	if (!data)
		ft_putstr("here\n");
	while (data[i])
	{
		j = 0;
		while (data[i][j].x != INT_STOP)
		{
			ft_putnbr(data[i][j].x);
			ft_putnbr(data[i][j].y);
			ft_putnbr(data[i][j].z);
			ft_putchar(32);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	// mlx_block;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 5120, 2880, "fdf");
	print_row(data, &mlx_ptr, &win_ptr);
	// line(0, 0, 100, 100, &mlx_ptr, &win_ptr);
	mlx_loop(mlx_ptr);

	// mlx_new_window - clear(for refresh) - destroy(create bigger window),

		system("leaks -q fdf");

	return (0);
}
