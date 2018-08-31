/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:04:28 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/31 14:52:25 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char *delete_colors_from_the_line(char *line)
{
	int i;
	int j;
	char *res;

	i = 0;
	j = 0;
	res = NULL;
	while (line[i] != ',')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));

	while (j < i)
	{
		res[j] = line[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

int		validation(char **data_file)
{
	size_t	i;
	size_t	j;
	int		some_digits;
	// char * buf;

	i = 0;
	while (data_file[i])
	{
		j = 0;
		some_digits = 0;
		// if (ft_str_find_chr(data_file[i], ','))
		// {
		// 	buf = delete_colors_from_the_line(data_file[i]);
		// 	free(data_file[i]);
		// 	data_file[i] = NULL;
		// 	data_file[i] = (char*)malloc(sizeof(char) * 3+1));
		// 	int q = 0;
		// 	while (q < 3)
		// 	{
		// 		data_file[i] = buf[i]; 
		// 	}
		// 	free(buf);
		// }
		while (j < ft_strlen(data_file[i]))
		{
			if (ft_isdigit(data_file[i][j]))
				some_digits++;
			if (ft_isdigit(data_file[i][j]) || data_file[i][j] == ' '
				|| data_file[i][j] == '\n' || data_file[i][j] == '\t'
				|| (data_file[i][j] == '-' && ft_isdigit(data_file[i][j + 1])))
				j++;
			else
			{
				return (0);
			}
		}
		if (!some_digits)
			return (0);
		i++;
	}
	return (1);
}
