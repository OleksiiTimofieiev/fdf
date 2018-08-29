/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:44:46 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/29 19:59:54 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		quantity_of_newline(char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (*line == '\n')
			i++;
		line++;
	}
	return (i);
}

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

double **transform_to_double(char *filename)
{
	double	**array;
	char	*data_from_file;

	array = NULL;
	data_from_file = NULL;


	data_from_file = get_contents(filename);


	if (data_from_file)
		array = (double **)malloc(sizeof(double *) * quantity_of_newline(data_from_file));
	else
	{
		ft_putstr("det2");

		return (NULL);
	}


	free(data_from_file);
	
	return (array);
}
