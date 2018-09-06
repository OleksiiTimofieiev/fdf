/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:55:13 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 12:38:15 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define INT_STOP 777
# define Y_LIMIT 2000
# define STEP_BASE 50
# define MONITOR_WIDTH 5120
# define MONITOR_HEIGHT 2880
# define TYPE_V_ROW 1
# define TYPE_V_LINE 0

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
	double		color;
}				t_coord;

typedef	struct	s_g
{
	int			**parsed_data;
	t_coord		**data;
	void		*mlx_ptr;
	void		*win_ptr;
	int			step;
}				t_g;

typedef	struct	s_buf
{
	int			x;
	int			y;
	int			w;
	int			h;
	int			dx1;
	int			dy1; 
	int			dx2;
	int			dy2;
	int			longest;
	int			shortest;
	int			numerator;
	int			iterator;
}				t_buf;

void			init_g(t_g *g);
int				validation(char **data_file);
void			initialization(int **array, char **data_from_file, int i);
int				**transform_to_int(char *filename);
t_coord			**fill_the_initial_matrix(int **parsed_data);
void			print(t_g *g);
void			line(t_g **g, int i, int j, int type_of_vector);

#endif
