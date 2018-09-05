/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/05 11:56:59 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: 1 dot; // broz to all sides;
// TODO: esc -> exit 0
// TODO: defines for colors;

void print_initial(t_coord **data, void **mlx_ptr, void **win_ptr)
{
	int i = 0;
	int j = 0;

	while (data[i])
	{
		j = 0;
		int z = 0;
		while (data[i][j].x != INT_STOP)
		{
			mlx_pixel_put(*mlx_ptr, *win_ptr, data[i][j].x + z, data[i][j].y + data[i][j].z, 0xFFFFFF);
			z+=10;
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

	// mlx_block;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	print_initial(data, &mlx_ptr, &win_ptr);
	mlx_loop(mlx_ptr);



	system("leaks -q fdf");
	
	return (0);
}
