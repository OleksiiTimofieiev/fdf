/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:44:46 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/31 14:53:02 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: size of the monitor


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
			free(data_from_file);
			return (NULL);
		}
		tmp = ft_strjoin(data_from_file, line);
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

static void		initialization(int **array, char **data_from_file, int i)
{
	int		j;
	char	**parsed_data;
	char	*before;
	char	*after;
	char	*buf;

	j = 0;
	buf = ft_strtrim(data_from_file[i]);
	parsed_data = ft_strsplit(buf, ' ');
	free(buf);
	array[i] = (int *)malloc(sizeof(int) * ft_strlen(data_from_file[i]) + 1);
	while (j < ft_2d_arr_size(parsed_data))
	{
		before = parsed_data[j];
		array[i][j] = ft_atoi(parsed_data[j]);
		after = ft_itoa(array[i][j++]);
		if (!ft_strequ(before, after))
		{
			free(after);
			exit(0);
		}
		free(after);
	}
	array[i][j] = INT_STOP;
	ft_clean_2d_char(parsed_data);
}

static	int		equality_of_rows(int **array)
{
	int i;
	int	j;
	int len;
	int count;

	// i = 0;
	// while(array[i])
	// {
	// 	j = 0;
	// 	while(array[i][j] != INT_STOP)
	// 	{
	// 		ft_putnbr(array[i][j]);
	// 		ft_putchar(' ');
	// 			j++;
	// 	}	
	// 	i++;
	// }
	i = 0;
	j = 0;
	len = 0;
	while (array[0][j++] != INT_STOP)
		len++;
	while (array[i])
	{
		j = 0;
		count = 0;
		while (array[i][j] != INT_STOP)
		{
			count++;
			j++;
		}
		if (count != len)
			return (0);
		i++;
	}
	return (1);
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
	ft_putstr("here2\n");
	return (NULL);
}
