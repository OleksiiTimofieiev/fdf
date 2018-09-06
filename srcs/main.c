/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 17:40:53 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// done: scale, color, moves in 2d, moves in 3d;

#include "../includes/fdf.h"

// TODO: 1 dot; // if i dot -> ups, do not want to work with it;
// TODO: info blocks;
// TODO: clean all possible leaks;
// TODO: parse color;
// TODO: gradient;

int main(int argc, char **argv)
{
	t_g	g;
	
	init_g(&g);
	if (argc == 2)
		(!(g.parsed_data = transform_to_int(argv[1]))) ? ft_putstr("Invalid data in the file.\n") : 0;
	(g.parsed_data) ? g.data = fill_the_initial_matrix(g.parsed_data) : exit(0); // TODO: func for exit;
	
	mlx_string_put(g.mlx_ptr, g.win_ptr, 1100, 650, 0xFFFFFF, "Please, push any button.");

	mlx_key_hook(g.win_ptr, deal_with_keyboard, &g);
	mlx_loop(g.mlx_ptr);

	system("leaks -q fdf");
	return (0);
}
