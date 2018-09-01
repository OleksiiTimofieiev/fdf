/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:44:46 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/01 14:02:28 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	open_the_file(int *fd, char *filename, char **data_from_file)
{
	*data_from_file = NULL;
	*data_from_file = ft_strnew(0);
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr("Not a valid file.\n");
		free(*data_from_file);
		exit(0);
	}
}

static char		*get_contents(char *filename)
{
	int		fd;
	char	*data_from_file;
	char	*line;
	char	*tmp;

	open_the_file(&fd, filename, &data_from_file);
	while (get_next_line(fd, &line))
	{
		if (line && !ft_strlen(line))
		{
			free(line);
			return (NULL);
		}
		tmp = ft_strjoin(data_from_file, line);
		(!tmp) ? exit(0) : 0;
		(data_from_file) ? free(data_from_file) : 0;
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

static	void	init(int *i, int *j, int *len, int *res)
{
	*i = 0;
	*j = 0;
	*len = 0;
	*res = 0;
}

static	int		equality_of_rows(int **array)
{
	int i;
	int	j;
	int len;
	int count;
	int res;

	init(&i, &j, &len, &res);
	while (array[0][j++] != INT_STOP)
		len++;
	while (array[i])
	{
		j = 0;
		count = 0;
		while (array[i][j] != INT_STOP)
		{
			count++;
			res = (array[i][j++] > Y_LIMIT) ? 0 : 1;
		}
		if (!res)
			return (0);
		res = (count != len) ? 0 : 1;
		i++;
	}
	return (res);
}

int				**transform_to_int(char *filename)
{
	int		**array;
	char	**data_file;
	char	*file_data;
	int		i;

	array = NULL;
	file_data = get_contents(filename);
	i = 0;
	data_file = (file_data) ? ft_strsplit(file_data, '\n') : NULL;
	if (data_file != NULL && validation(data_file))
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
