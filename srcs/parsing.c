/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:44:46 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/29 18:51:46 by otimofie         ###   ########.fr       */
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
	line = NULL;
	tmp = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strjoin(data_from_file, line);
		free(data_from_file);
		data_from_file = ft_strjoin(data_from_file, tmp);
		free(tmp);
		free(line);
	}
	if (close(fd) == -1)
		return (NULL);
	return (data_from_file);
}

// char *gtransform_to_double(char *data)
// {
	
// }
