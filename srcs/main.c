/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/01 15:17:23 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: parsing -> add to linked list;

//TODO: 1 dot; // broz to all sides;

int		len_of_int_rows(int *parsed_data)
{
	int i;

	i = 0;
	while(parsed_data[i] != INT_STOP)
		i++;
	return (i);
}

void fill_the_initial_matrix(t_coord **data, int **parsed_data)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	
	data = (t_coord **)malloc(sizeof(t_coord *) * len_of_int_rows(parsed_data[0]) + 1);

	while(i < 3)
	{
		data[i] = (t_coord *)malloc(sizeof(t_coord) * 3);
		j = 0;
		while (j < 3)
		{
			data[i][j].x = j;
			data[i][j].y = i;
			data[i][j].z = parsed_data[i][j];
			j++;
		}
		i++;
	}
	// i = 0;
	// while (i < 3)
	// {
	// 	j = 0;
	// 	while (j < 3)
	// 	{
	// 		ft_putnbr(data[i][j].x);
	// 		ft_putnbr(data[i][j].y);
	// 		ft_putnbr(data[i][j].z);
	// 		ft_putchar(32);
	// 		j++;
	// 	}
	// 	ft_putchar('\n');
	// 	i++;
	// }
	
}

int		main(int argc, char **argv)
{
	t_coord		**data;



	int **parsed_data = NULL;
	if (argc == 2)
    {
        parsed_data = transform_to_int(argv[1]);
		if(!parsed_data)
			ft_putstr("Invalid data in the file.\n");
	}

	
	fill_the_initial_matrix(data, parsed_data);

	int i = 0;
	int j = 0;

	if(!data)
		ft_putstr("here\n");
	while (data[i])
	{
		j = 0;
		while (j < 3)
		{
			ft_putnbr(data[i][j].x);
			ft_putnbr(data[i][j].y);
			ft_putnbr(data[i][j].z);
			ft_putchar(32);
			j++;
		}
		ft_putchar('\n');
		i++;
	}

	system("leaks -q fdf");

	return (0);
}