/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/01 11:20:29 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: parsing -> add to linked list;

//TODO: 1 dot; // broz to all sides;



int     main(int argc, char ** argv)
{
    int ** test = NULL;
    if (argc == 2)
    {
        test = transform_to_int(argv[1]);
		if(!test)
			ft_putstr("Invalid data in the file.\n");

		int i = 0;
		unsigned long j = 0;

		while (test[i])
		{
			j = 0;
			while (test[i][j] != INT_STOP)
			{
				ft_putnbr(test[i][j]);
				ft_putchar(32);

				j++;
			}
			ft_putchar('\n');
			i++;
		}
	}


	system("leaks -q fdf");

	return (0);
}