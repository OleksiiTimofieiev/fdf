/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/01 14:28:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: parsing -> add to linked list;

//TODO: 1 dot; // broz to all sides;

int		len_of_int_rows(int **parsed_data)
{
	int i;

	i = 0;
	while(parsed_data[i])
		i++;
	return (i);
}

void	fill_the_initial_matrix(t_coord **data, int **parsed_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if(!(data = (t_coord **)malloc(sizeof(t_coord*) * len_of_int_rows(parsed_data) + 1)))
		return ;

	data[len_of_int_rows(parsed_data)] = NULL;

	while(data[i])
	{
		data[i] = (t_coord *)malloc(sizeof(t_coord) * (sizeof(parsed_data[i]) / sizeof(int)));
		j = 0;
		while (j < (int)(sizeof(parsed_data[i]) / sizeof(int)))
		{
			data[i]->x = j;
			data[i]->y = i;
			data[i]->z = parsed_data[i][j];
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_coord		**data;

	data = NULL;

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

	int **parsed_data = NULL;
	if (argc == 2)
    {
        parsed_data = transform_to_int(argv[1]);
		if(!parsed_data)
			ft_putstr("Invalid data in the file.\n");

		// int i = 0;
		// unsigned long j = 0;

		// while (test[i])
		// {
		// 	j = 0;
		// 	while (test[i][j] != INT_STOP)
		// 	{
		// 		ft_putnbr(test[i][j]);
		// 		ft_putchar(32);

		// 		j++;
		// 	}
		// 	ft_putchar('\n');
		// 	i++;
		// }
	}
	fill_the_initial_matrix(data, parsed_data);


		system("leaks -q fdf");

	return (0);
}