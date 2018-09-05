/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/05 11:18:10 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: parsing -> add stop value;

//TODO: 1 dot; // broz to all sides;


int		main(int argc, char **argv)
{
	int **parsed_data;
	t_coord		**data;

	data = NULL;
	parsed_data = NULL;
	if (argc == 2)
    {
		if (!(parsed_data = transform_to_int(argv[1])))
			ft_putstr("Invalid data in the file.\n");
	}
	(parsed_data) ? data = fill_the_initial_matrix(parsed_data) : exit(0);
	system("leaks -q fdf");
	return (0);
}