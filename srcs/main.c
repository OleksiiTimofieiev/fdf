/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 17:12:54 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"



// done: scale, color, moves in 2d, moves in 3d;

// TODO: 1 dot; // broz to all sides;
// TODO: https://www.tutorialspoint.com/c_standard_library/math_h.htm
// TODO: info blocks;
// TODO: clean all possible leaks;
// TODO: parse color;
// TODO: leaks;
// TODO: gradient;

int main(int argc, char **argv)
{
	// int deal_with_keyboard_key = 0;;
	t_g	g;
	
	init_g(&g);
	if (argc == 2)
		(!(g.parsed_data = transform_to_int(argv[1]))) ? ft_putstr("Invalid data in the file.\n") : 0;
	(g.parsed_data) ? g.data = fill_the_initial_matrix(g.parsed_data) : exit(0); // TODO: func for exit;
	
	g.mlx_ptr = mlx_init();
	g.win_ptr = mlx_new_window(g.mlx_ptr, MONITOR_WIDTH, MONITOR_HEIGHT, "fdf");
			
	print(&g);
	mlx_key_hook(g.win_ptr, deal_with_keyboard, &g);
	mlx_loop(g.mlx_ptr);



	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_new_window - clear(for refresh) - destroy(create bigger window),

	system("leaks -q fdf");

	return (0);
}
