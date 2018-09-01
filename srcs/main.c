/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/01 13:39:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: parsing -> add to linked list;

//TODO: 1 dot; // broz to all sides;



int     main(int argc, char ** argv)
{
	// t_coord		**z;

	// z = (t_coord**)malloc(sizeof(t_coord*));

	// z[0] = (t_coord *)malloc(sizeof(t_coord )*2);

	// z[0][0].x = 1;
	// z[0][0].y = 2;

	// z[0][1].x = 3;
	// z[0][1].y = 4;

	// ft_putnbr(z[0][0].x);
	// ft_putchar('\n');
	// ft_putnbr(z[0][0].y);
	// ft_putchar('\n');

	// ft_putchar('\n');

	// ft_putnbr(z[0][1].x);
	// ft_putchar('\n');
	// ft_putnbr(z[0][1].y);
	// ft_putchar('\n');

	// ft_putchar('\n');

	int **test = NULL;
	if (argc == 2)
    {
        test = transform_to_int(argv[1]);
		if(!test)
			ft_putstr("Invalid data in the file.\n");

	// 	int i = 0;
	// 	unsigned long j = 0;

	// 	while (test[i])
	// 	{
	// 		j = 0;
	// 		while (test[i][j] != INT_STOP)
	// 		{
	// 			ft_putnbr(test[i][j]);
	// 			ft_putchar(32);

	// 			j++;
	// 		}
	// 		ft_putchar('\n');
	// 		i++;
	// 	}
	}


	system("leaks -q fdf");

	return (0);
}