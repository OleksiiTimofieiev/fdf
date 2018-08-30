/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:44:46 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/30 14:54:30 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO: 1 dot; // different len of the strings; // broz to all sides;

static char	*get_contents(char *filename)
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
		ft_putstr("det\n");
		
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

static void	initialization(int **array, char **data_from_file, int i)
{
	char	**parsed_data;
	int		j;

	j = 0;
	parsed_data = ft_strsplit(data_from_file[i], 32);
	array[i] = (int *)malloc(sizeof(int) * ft_strlen(data_from_file[i]) + 1);
	while (j < ft_2d_arr_size(parsed_data))
	{
		array[i][j] = ft_atoi(parsed_data[j]);
		j++;
	}
	array[i][j] = INT_STOP;
	ft_clean_2d_char(parsed_data);
}

int			**transform_to_int(char *filename)
{
	int		**array;
	char	**data_file;
	char	*file_data;
	int		i;

	array = NULL;
	file_data = NULL;
	data_file = NULL;
	file_data = get_contents(filename);
	i = 0;
	if (file_data)
		data_file = ft_strsplit(file_data, '\n');
	if (data_file)
	{
		array = (int **)malloc(sizeof(int*) * ft_2d_arr_size(data_file) + 1);
		while (i < ft_2d_arr_size(data_file))
			initialization(array, data_file, i++);
		array[ft_2d_arr_size(data_file)] = NULL;
	}
	if (data_file)
		ft_clean_2d_char(data_file);
	if (file_data)
		free(file_data);
	return (array);
}
