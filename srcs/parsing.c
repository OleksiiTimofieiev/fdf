/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:44:46 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/30 17:01:33 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// TODO: 1 dot; // different len of the strings; // broz to all sides; // size of the monitor

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
	int		j;
	char	**parsed_data;
	char	*before;
	char	*after;
	char*buf;

	j = 0;
	buf = ft_strtrim(data_from_file[i]);
	parsed_data = ft_strsplit(buf, 32);
	free(buf);
	array[i] = (int *)malloc(sizeof(int) * ft_strlen(data_from_file[i]) + 1);
	while (j < ft_2d_arr_size(parsed_data))
	{
		before = parsed_data[j];
		array[i][j] = ft_atoi(parsed_data[j]);
		after = ft_itoa(array[i][j]);
		if (!ft_strequ(before, after))
		{
			free(after);
			exit(0);
		}
		free(after);
		j++;
	}
	array[i][j] = INT_STOP;
	ft_clean_2d_char(parsed_data);
}

static int	validation(char **data_file)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data_file[i])
	{
		j = 0;
		while (j < ft_strlen(data_file[i]))
		{
			if (ft_isdigit(data_file[i][j])
				|| data_file[i][j] == ' '
				|| data_file[i][j] == '\n'
				|| data_file[i][j] == '\t'
				|| (data_file[i][j] == '-' && ft_isdigit(data_file[i][j + 1])))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int			int_array_len(int *array)
{
	int i;

	i = 0;
	while (array[i] != INT_STOP)
		i++;
	return (i);
}

int			equality_of_rows(int **array)
{
	int i;
	int len;

	i = 0;
	len = int_array_len(array[i]);
	while (array[i])
	{
		if (int_array_len(array[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int			**transform_to_int(char *filename)
{
	int		**array;
	char	**data_file;
	char	*file_data;
	int		i;

	array = NULL;
	file_data = get_contents(filename);
	i = 0;
	data_file = (file_data) ? ft_strsplit(file_data, '\n') : NULL;
	if (data_file && validation(data_file))
	{
		array = (int **)malloc(sizeof(int*) * ft_2d_arr_size(data_file) + 1);
		while (i < ft_2d_arr_size(data_file))
			initialization(array, data_file, i++);
		array[ft_2d_arr_size(data_file)] = NULL;
	}
	(data_file) ? ft_clean_2d_char(data_file) : 0;
	(file_data) ? free(file_data) : 0;
	if (array && equality_of_rows(array))
		return (array);
	return (NULL);
}
