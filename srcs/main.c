/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/31 11:08:16 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: parsing -> add to linked list;

//TODO: validation

int     main(int argc, char ** argv)
{
    int ** test = NULL;
    if (argc == 2)
    {
        test = transform_to_int(argv[1]);
		if(!test)
			ft_putstr("No data in the file.\n");

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