#ifndef FDF_H
# define FDF_H
# define INT_STOP 777
#define Y_LIMIT 2000

#include <stdio.h>
#include <fcntl.h>

#include "../libft/libft.h"

typedef struct s_data
{
    double ** data;
}              t_data;

int		validation(char **data_file);
void	initialization(int **array, char **data_from_file, int i);
int		**transform_to_int(char *filename);

#endif