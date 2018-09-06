/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:55:13 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/06 11:28:07 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define INT_STOP 777
# define Y_LIMIT 2000
# define STEP_BASE 50
# define MONITOR_WIDTH 5120
# define MONITOR_HEIGHT 2880

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

void			init_g(t_g *g);
int				validation(char **data_file);
void			initialization(int **array, char **data_from_file, int i);
int				**transform_to_int(char *filename);
t_coord			**fill_the_initial_matrix(int **parsed_data);
void			print(t_g *g);
void			line(int x, int y, int x2, int y2, void **mlx_ptr, void **win_ptr); // TODO:pass data[i][j];

#endif
