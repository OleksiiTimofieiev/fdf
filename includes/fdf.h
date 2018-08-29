#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <fcntl.h>

#include "../libft/libft.h"

typedef struct s_data
{
    double ** data;
}              t_data;

char *getContents(char *filename);

#endif