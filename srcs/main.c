/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/30 11:33:37 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: parsing;

//TODO: validation

//TODO: parsing and validation in one func;


int     main(int argc, char ** argv)
{
    double ** test = NULL;
    if (argc == 2)
    {
        test = transform_to_double(argv[1]);
		if(!test)
			ft_putstr("No data in the file.\n"); // TODO: handle it;
    }


    system("leaks -q fdf");

    return (0);
}