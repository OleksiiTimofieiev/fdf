/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/30 14:01:59 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: parsing;

//TODO: validation

//TODO: parsing and validation in one func;


int     main(int argc, char ** argv)
{
    int ** test = NULL;
    if (argc == 2)
    {
        test = transform_to_int(argv[1]);
		if(!test)
			ft_putstr("No data in the file.\n"); // TODO: handle it;





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