/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:44:46 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/30 13:36:38 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*get_contents(char *filename)
{
	int		fd;
	char	*data_from_file;
	char	*line;
	char	*tmp;

	data_from_file = ft_strnew(0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(data_from_file);
		return (NULL);
	}
	while (get_next_line(fd, &line))
	{
		tmp = ft_strjoin(data_from_file, line);
		free(data_from_file);
		data_from_file = ft_strnew(ft_strlen(tmp) + 1);
		ft_strcpy(data_from_file, tmp);
		data_from_file[ft_strlen(tmp)] = '\n';
		free(tmp);
		free(line);
	}
	if (close(fd) == -1)
		return (NULL);
	return (data_from_file);
}

int **transform_to_int(char *filename)
{
	int	**array;
	char	**data_from_file;
	char	**parsed_data;
	char *test = get_contents(filename);
	int	i;
	int j;


	array = NULL;


	data_from_file = ft_strsplit(test, '\n');

	i = 0;
	if (data_from_file)
	{
		array = (int **)malloc(sizeof(int*) * ft_2d_arr_size(data_from_file) + 1);
		while (i < ft_2d_arr_size(data_from_file))
		{



			
			array[i] = (int *)malloc(sizeof(int) * ft_strlen(data_from_file[i]));
			j = 0;

				parsed_data = ft_strsplit(data_from_file[i], 32); // TODO: 1 dot;
				while (j < ft_2d_arr_size(parsed_data))
				{
					array[i][j] = ft_atoi(parsed_data[j]);
					j++;
				}
				ft_clean_2d_char(parsed_data);

				i++;
		}
		array[ft_2d_arr_size(data_from_file)] = NULL;
	}
	ft_clean_2d_char(data_from_file);
	free(test);
	return (array);
}
