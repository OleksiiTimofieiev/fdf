/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:04:28 by otimofie          #+#    #+#             */
/*   Updated: 2018/08/31 17:32:29 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char *delete_colors_from_the_line(char *line) //use some backtracking or recursion;
{
	int	i;
	int	flag_bool;

	i = 0;
	flag_bool = 0;

	while(line[i])
	{
		if(line[i] ==',')
			flag_bool = 1;
		else if(line[i] == ' ' || line[i] == '\t')
			flag_bool = 0;
		if(flag_bool)
			line[i] = '*';
		i++;
	}

	i = 0;
	int count = 0;
	while(line[i++])
	{
		if(line[i] != '*')
			count++;
		i++;
	}
	char * res;
	
	res = (char *)malloc(sizeof(char) * (count + 1));
	
	i = 0;

	while(*line)
	{
		if (*line != '*')
		{
			res[i] = *line;
			i++;
		}
		line++;
	}
	res[i] = '\0';
	
	return (res);
}

int		validation(char **data_file)
{
	size_t	i;
	size_t	j;
	int		some_digits;
	char * buf = NULL;

	i = 0;
	while (data_file[i])
	{
		j = 0;
		some_digits = 0;
		if (ft_str_find_chr(data_file[i], ','))
		{
			buf = delete_colors_from_the_line(data_file[i]);
			free(data_file[i]);
			data_file[i] = ft_strdup(buf);
			free(buf);
		}
		while (j < ft_strlen(data_file[i]))
		{
			if (ft_isdigit(data_file[i][j]))
				some_digits++;
			if (ft_isdigit(data_file[i][j]) || data_file[i][j] == ' '
				|| data_file[i][j] == '\n' || data_file[i][j] == '\t'
				|| (data_file[i][j] == '-' && ft_isdigit(data_file[i][j + 1])))
				j++;
			else
				return (0);
		}
		if (!some_digits)
			return (0);
		i++;
	}
	return (1);
}
