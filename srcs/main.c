/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 22:36:35 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO: leaks put image;
// TODO: parsing of colors;
// TODO: ?: printing according to the color of each element;

// TODO: leaks on each step;

int		main(int argc, char **argv)
{
	t_g	g;

	if (argc >= 2 && argc <= 3)
	{
		init_g(&g, &argv[1]);
		if (argc == 3 && ft_strequ("-i", argv[2]))
			g.gradient = (ft_strequ("-i", argv[2])) ? 2.0 : -2.0;
		else if (argc == 3 && !ft_strequ("-i", argv[2]))
		{
			ft_putstr("Bad input.\n");
			exit(0);
		}
		(g.parsed_data) ? g.data = fill_the_initial_matrix(g.parsed_data) : exit(0);
		mlx_key_hook(g.win_ptr, deal_with_keyboard, &g);
		mlx_loop(g.mlx_ptr);
	}
	else
		ft_putstr("Bad input.\n");
	return (0);
}
