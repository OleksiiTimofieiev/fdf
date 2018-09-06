/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 17:09:11 by otimofie         ###   ########.fr       */
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



void	change_color(int key, t_g **g)
{
	if (key == 12)
		(*g)->color = BLUE_COLOR;
	else if (key == 13)
		(*g)->color = YELLOW_COLOR;
	else if (key == 14)
		(*g)->color = MAGENTA_COLOR;
	else if (key == 15)
		(*g)->color = INIT_COLOR;
}

void	change_position(int key, t_g **g)
{
	if (key == 126)
		(*g)->correction_y -= MOV_SCALE;
	else if (key == 125)
		(*g)->correction_y += MOV_SCALE;
	else if (key == 123)
		(*g)->correction_x -= MOV_SCALE;
	else if (key == 124)
		(*g)->correction_x += MOV_SCALE;
}

void	change_scale(int key, t_g **g)
{
	if (key == 69)
		(*g)->step += SCALE;
	else if (key == 78)
		(*g)->step -= SCALE;
}

int		deal(int key, t_g *g)
{
	if (key == 53)
	{
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		exit(1);
		return(0);
	}
	change_color(key, &g);
	change_position(key, &g);
	change_scale(key, &g);
	rotate(key, &g);
		mlx_clear_window(g->mlx_ptr, g->win_ptr);
	print(g);
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
