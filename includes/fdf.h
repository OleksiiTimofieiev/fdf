/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:55:13 by otimofie          #+#    #+#             */
/*   Updated: 2018/09/05 16:25:21 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define INT_STOP 777
# define Y_LIMIT 2000
# define STEP 50

# include <stdio.h>
# include <fcntl.h>
#include <math.h>
# include "../libft/libft.h"
# include <mlx.h>

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
	double		color;
}				t_coord;

int				validation(char **data_file);
void			initialization(int **array, char **data_from_file, int i);
int				**transform_to_int(char *filename);
t_coord			**fill_the_initial_matrix(int **parsed_data);

#endif
