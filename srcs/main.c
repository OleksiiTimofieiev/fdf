#include "../includes/fdf.h"

//TODO: parsing;

//TODO: validation


int     main(int argc, char ** argv)
{
    char * test = NULL;
    if (argc == 2)
    {
        test = getContents(argv[1]);
            printf("%s\n", test);
    }

    system("leaks -q fdf");

    return (0);
}