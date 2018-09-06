/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 15:08:53 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// done: scale, color, moves in 2d;

// TODO: 1 dot; // broz to all sides;
// TODO: esc -> exit 0
// TODO: https://www.tutorialspoint.com/c_standard_library/math_h.htm
// TODO: default angle;
// TODO: MATRIX of rotation;
// TODO: info blocks;
// TODO: clean all possible leaks;

int	deal(int key, t_g *param) // aTODO:rray of function pointers
{
	if (key == 12)
		param->color = BLUE_COLOR;
	else if (key == 13)
		param->color = YELLOW_COLOR;
	else if (key == 14)
		param->color = MAGENTA_COLOR;
	else if (key == 15)
		param->color = INIT_COLOR;
	else if (key == 126)
		param->correction_y -= MOV_SCALE;
	else if (key == 125)
		param->correction_y += MOV_SCALE;
	else if (key == 123)
		param->correction_x -= MOV_SCALE;
	else if (key == 124)
		param->correction_x += MOV_SCALE;
	else if (key == 69)
		param->step += SCALE;
	else if (key == 78)
		param->step -= SCALE;
	else if (key == 53)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		exit(1);
		return(0);
	}
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	print(param);
	return (0);
}


int main(int argc, char **argv)
{
	// int deal_key = 0;;
	t_g	g;
	
	init_g(&g);
	if (argc == 2)
		(!(g.parsed_data = transform_to_int(argv[1]))) ? ft_putstr("Invalid data in the file.\n") : 0;
	(g.parsed_data) ? g.data = fill_the_initial_matrix(g.parsed_data) : exit(0); // TODO: func for exit;
	
	g.mlx_ptr = mlx_init();
	g.win_ptr = mlx_new_window(g.mlx_ptr, MONITOR_WIDTH, MONITOR_HEIGHT, "fdf");

	print(&g);
	

	mlx_key_hook(g.win_ptr, deal, &g);
	mlx_loop(g.mlx_ptr);



	// mlx_clear_window(mlx_ptr, win_ptr);
	// mlx_new_window - clear(for refresh) - destroy(create bigger window),

	system("leaks -q fdf");

	return (0);
}
