#include "../includes/fdf.h"

//TODO: parsing;

//TODO: validation

//TODO: parsing and validation in one func;


int     main(int argc, char ** argv)
{
    double ** test = NULL;
    if (argc == 2)
    {
        test = transform_to_double(argv[1]);
    }


    system("leaks -q fdf");

    return (0);
}