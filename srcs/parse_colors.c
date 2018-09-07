/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:06:23 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/07 11:38:47 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int hexadecimalToDecimal(char *hexVal)
{   
    int len = strlen(hexVal);
     
    // Initializing base value to 1, i.e 16^0
    int base = 1;
     
    int dec_val = 0;
     
    // Extracting characters as digits from last character
    for (int i=len-1; i>=0; i--)
    {   
        // if character lies in '0'-'9', converting 
        // it to integral 0-9 by subtracting 48 from
        // ASCII value.
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;
                 
            // incrementing base by power
            base = base * 16;
        }
 
        // if character lies in 'A'-'F' , converting 
        // it to integral 10 - 15 by subtracting 55 
        // from ASCII value
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base;
         
            // incrementing base by power
            base = base*16;
        }
    }
     
    return dec_val;
}

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

void	print_array(t_coord **array)
{
	int i = 0;
	int j = 0;

	while(array[i])
	{
		j = 0;
		while(array[i][j].x != INT_STOP)
		{
			ft_putnbr(array[i][j].color);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	parse_colors(t_g *g, char *argv)
{
	int i = 0;
	int j = 0;
	char *file_contents;
	char **after_newline;
	// char **after_space;

	file_contents = get_file_contents(argv);
	after_newline = ft_strsplit(file_contents, '\n');
	free(file_contents);
	
	while(after_newline[i])
	{
		// after_space = ft_strsplit(after_newline[i], ' ');
		j = 0;
		while(g->data[i][j].x != INT_STOP)
		{
			g->data[i][j].color = MAGENTA_COLOR;
			j++;
		}
		i++;
	}
	ft_clean_2d_char(after_newline);
	


	print_array((g)->data);
}