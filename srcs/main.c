/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 11:18:08 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO: 1 dot; // broz to all sides;
// TODO: esc -> exit 0
// TODO: defines for colors;
// TODO: сдвиг left/right; scale with map limits
// TODO: https://www.tutorialspoint.com/c_standard_library/math_h.htm
// TODO: mo
// TODO: add prefix;

int main(int argc, char **argv)
{
	t_general	general;
	
	init_general(&general);
	if (argc == 2)
		(!(general.parsed_data = transform_to_int(argv[1]))) ? ft_putstr("Invalid data in the file.\n") : 0;
	(general.parsed_data) ? general.data = fill_the_initial_matrix(general.parsed_data) : exit(0); // TODO: func for exit;
	
	general.mlx_ptr = mlx_init();
	general.win_ptr = mlx_new_window(general.mlx_ptr, MONITOR_WIDTH, MONITOR_HEIGHT, "fdf");

	print(&general);


	
	mlx_loop(general.mlx_ptr);



	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_new_window - clear(for refresh) - destroy(create bigger window),

	system("leaks -q fdf");

	return (0);
}
