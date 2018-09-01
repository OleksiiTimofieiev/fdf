/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 11:33:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/01 15:31:14 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: parsing -> add to linked list;

//TODO: 1 dot; // broz to all sides;

int		rows(int **parsed_data)
{
	int i;

	i = 0;
	while(parsed_data[i])
		i++;
	return (i);
}

int 	size_row(int *parsed_data)
{
	int i;

	i = 0;
	while (parsed_data[i] != INT_STOP)
		i++;
	return (i);
}

t_coord **fill_the_initial_matrix(int **parsed_data)
{
	t_coord **res;
	int	i;
	int	j;

	i = 0;
	j = 0;
	res = NULL;
	if(!(res = (t_coord **)malloc(sizeof(t_coord *) * rows(parsed_data) + 1)))
		return (NULL);
	while (i < rows(parsed_data))
	{
		if (!(res[i] = (t_coord *)malloc(sizeof(t_coord) * size_row(parsed_data[i]))))
			return (NULL);
		j = 0;
		while (j < size_row(parsed_data[i]))
		{
			res[i][j].x = j;
			res[i][j].y = i;
			res[i][j].z = parsed_data[i][j];
			j++;
		}
		i++;
	}
	res[i] = NULL;
	return(res);
}

int		main(int argc, char **argv)
{
	t_coord		**data;

	data = NULL;


	int **parsed_data = NULL;
	if (argc == 2)
    {
        parsed_data = transform_to_int(argv[1]);
		if(!parsed_data)
			ft_putstr("Invalid data in the file.\n");
	}

	data = fill_the_initial_matrix(parsed_data);

	int i = 0;
	int j = 0;

	if(!data)
		ft_putstr("here\n");
	while (data[i])
	{
		j = 0;
		while (j < 4)
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