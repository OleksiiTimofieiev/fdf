/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:06:23 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/08 10:53:48 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	open_the_file(int *fd, char *filename, char **data_from_file)
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

char	*get_file_contents(char *filename)
{
	int		fd;
	char	*data_from_file;
	char	*line;
	char	*tmp;

	open_the_file(&fd, filename, &data_from_file);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strjoin(data_from_file, line);
		check_tmp(&tmp, fd);
		(data_from_file) ? free(data_from_file) : 0;
		data_from_file = ft_strnew(ft_strlen(tmp) + 1);
		ft_strcpy(data_from_file, tmp);
		data_from_file[ft_strlen(tmp)] = '\n';
		(tmp) ? free(tmp) : 0;
		check_line(&line, fd);
	}
	if (close(fd) == -1)
		return (NULL);
	return (data_from_file);
}

int		validate_line_with_color(char *str_for_analysis)
{
	int i;

	i = 2;
	if (str_for_analysis[0] != '0')
		return (0);
	else if (ft_strlen(str_for_analysis) < 3 || ft_strlen(str_for_analysis) > 8)
		return (0);
	else if (str_for_analysis[1] != 'x') 
		return (0);
	while (str_for_analysis[i])
	{
		if (ft_isdigit(str_for_analysis[i]) || str_for_analysis[i] != 'A'
			|| str_for_analysis[i] != 'B' || str_for_analysis[i] != 'C'
			|| str_for_analysis[i] != 'D' || str_for_analysis[i] != 'E'
			|| str_for_analysis[i] != 'F')
			i++;
		else
			return (0);
	}
	return (1);
}

int		validation_of_colors(char *after_space, char **buf)
{
	int				count;
	char			*str_for_analysis;
	unsigned long	i;
	unsigned long	j;

	count = 0;
	if (!ft_str_find_chr(after_space, ','))
		return (0);
	while (after_space[count] && after_space[count] != ',')
		count++;
	if (count == 0)
		return (0);
	if (!(str_for_analysis = (char*)malloc(sizeof(char)
		* (ft_strlen(after_space) - (count + 1) + 1))))
		return (0);
	i = 0;
	j = ft_strlen(after_space) - (count + 1);
	while (i < j)
		str_for_analysis[i++] = after_space[count++ + 1];
	str_for_analysis[i] = '\0';

	// TODO: // if (!rules)
			 // 	return (0);
	// Colors parsing:
	// - len [3-8];
	// - first element is char '0';
	// - second element is char 'x';
	// - possible elements after [0 - 9] || [A - F];

	// TODO: - equal quantity of '\n';
	if (!validate_line_with_color(str_for_analysis))
		return (0);
	*buf = ft_strdup(str_for_analysis);
	free(str_for_analysis);
	return (1);
}

void	parse_colors_main_cycle(char **after_newline, char **after_space,
								char **buf, t_g **g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (after_newline[i])
	{
		after_space = ft_strsplit(after_newline[i], ' ');
		j = 0;
		while ((*g)->data[i][j].x != INT_STOP)
		{
			*buf = NULL;
			if (validation_of_colors(after_space[j], buf))
				(*g)->data[i][j].color = hex_int_converter(*buf);
			free(*buf);
			j++;
		}
		ft_clean_2d_char(after_space);
		i++;
	}
}

void	parse_colors(t_g *g, char *argv)
{
	char	*file_contents;
	char	**after_newline;
	char	**after_space;
	char	*buf;

	after_space = NULL;
	file_contents = get_file_contents(argv);
	after_newline = ft_strsplit(file_contents, '\n');
	free(file_contents);
	parse_colors_main_cycle(after_newline, after_space, &buf, &g);
	ft_clean_2d_char(after_newline);
}
