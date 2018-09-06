/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 18:27:35 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// done: scale, color, moves in 2d, moves in 3d matrix transponation, 
// different colors on heights, depending from the angle;
// -i -> invinsible;

#include "../includes/fdf.h"

// TODO: 1 dot; // if i dot -> ups, do not want to work with it;
// TODO: clean all possible leaks;
// TODO: parse color;

int main(int argc, char **argv)
{
	t_g	g;
	
	init_g(&g);
	if (argc == 2 || argc == 3)
		(!(g.parsed_data = transform_to_int(argv[1]))) ? ft_putstr("Invalid data in the file.\n") : 0;
	if(argc == 3)
		g.gradient = (!ft_strequ("-i", argv[2])) ? -2.0 : 2;
	(g.parsed_data) ? g.data = fill_the_initial_matrix(g.parsed_data) : exit(0);
	mlx_key_hook(g.win_ptr, deal_with_keyboard, &g);
	mlx_loop(g.mlx_ptr);
	system("leaks -q fdf");
	return (0);
}
