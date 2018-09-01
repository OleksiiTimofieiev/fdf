/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:04:28 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/01 10:44:20 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//TODO: size of the monitor

static	void	place_stars(char *line, int *i, int *count)
{
	int j;
	int flag_bool;

	j = 0;
	flag_bool = 0;
	while (line[j])
	{
		if (line[j] == ',')
			flag_bool = 1;
		else if (line[j] == ' ' || line[j] == '\t')
			flag_bool = 0;
		if (flag_bool)
			line[j] = '*';
		j++;
	}
	*i = 0;
	*count = 0;
}

char			*delete_colors_from_the_line(char *line)
{
	int		i;
	int		count;
	char	*res;

	place_stars(line, &i, &count);
	while (line[i])
	{
		if (line[i] != '*')
			count++;
		i++;
	}
	if (!(res = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	i = 0;
	while (*line)
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

static	void	replace(char **data_file, int *i)
{
	char *buf;

	buf = NULL;
	if (ft_str_find_chr(*data_file, ','))
	{
		buf = delete_colors_from_the_line(*data_file);
		free(*data_file);
		*data_file = ft_strdup(buf);
		free(buf);
	}
	*i = 0;
}

int				validation(char **data_file)
{
	size_t	i;
	size_t	j;
	int		some_digits;

	i = 0;
	while (data_file[i])
	{
		j = 0;
		replace(&data_file[i], &some_digits);
		while (j < ft_strlen(data_file[i]))
		{
			if (ft_isdigit(data_file[i][j]))
				some_digits++;
			if (ft_isdigit(data_file[i][j]) || data_file[i][j] == ' '
				|| data_file[i][j] == '\n'
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
