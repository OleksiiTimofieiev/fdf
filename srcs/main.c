/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/08 11:12:04 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: equal quantity of '\n';
// TODO: check leaks;

#include "../includes/fdf.h"

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
		(g.parsed_data) ? g.data = fill_the_matrix(g.parsed_data) : exit(0);
		parse_colors(&g, argv[1]);
		// exit(0);
		mlx_key_hook(g.win_ptr, deal_with_keyboard, &g);
		mlx_loop(g.mlx_ptr);
	}
	else
		ft_putstr("Bad input.\n");
	return (0);
}
