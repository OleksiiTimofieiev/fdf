#ifndef FDF_H
# define FDF_H
# define INT_STOP 777

#include <stdio.h>
#include <fcntl.h>

#include "../libft/libft.h"

typedef struct s_data
{
    double ** data;
}              t_data;

int		**transform_to_int(char *filename);
int		validation(char **data_file);

#endif