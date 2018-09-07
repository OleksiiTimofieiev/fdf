/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:55:13 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/07 16:26:07 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define INT_STOP 777
# define Y_LIMIT 2000
# define INIT_SCALE 5
# define SCALE 5

# define INIT_CORRECTION_X 1100
# define INIT_CORRECTION_Y 600

# define INIT_COLOR 0xFFFFFF
# define BLUE_COLOR 0x0000FF
# define YELLOW_COLOR 0xFFFF00
# define MAGENTA_COLOR 0xFF00FF
# define GREEN_COLOR 0x008000

# define MONITOR_WIDTH 5120
# define MONITOR_HEIGHT 2880
# define TYPE_V_ROW 1
# define TYPE_V_LINE 0

# define MOV_SCALE 50

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_coord;

typedef	struct		s_g
{
	int				**parsed_data;
	t_coord			**data;
	void			*mlx_ptr;
	void			*win_ptr;
	int				step;
	int				color;
	int				correction_x;
	int				correction_y;
	int				corner;
	float			gradient;
}					t_g;

typedef	struct		s_buf
{
	double			x;
	double			y;
	double			w;
	double			h;
	double			dx1;
	double			dy1;
	double			dx2;
	double			dy2;
	int				longest;
	double			shortest;
	double			numerator;
	double			iterator;
	double			color;
}					t_buf;

void				init_g(t_g *g, char **argv);
int					len_max(int **array);
int					validation(char **data_file);
void				initialization(int **array, char **data_from_file, int i);
int					**transform_to_int(char *filename);
t_coord				**fill_the_matrix(int **parsed_data);
void				print(t_g *g);
void				line(t_g **g, int i, int j, int type_of_vector);
void				rotate(int key, t_g **g);
int					deal_with_keyboard(int key, t_g *g);
int					size_double(int **array);
void				check_line(char **line, int fd);
void				check_tmp(char **tmp, int fd);
void				parse_colors(t_g *g, char *argv);

#endif
