#include "../includes/fdf.h"

//TODO: parsing;

//TODO: validation

char *get_contents(char * filename)
{
    int     fd;
    char*   data_from_file;
    char*   line;
    char*   tmp;
    



    data_from_file = "";
    line = "";
    tmp = "";


    fd = open(filename, O_RDONLY);

    if (fd == -1)
        return (NULL);

    while (get_next_line(fd, &line))
    {
        data_from_file = ft_strjoin(data_from_file, line);

        free(line);
    }


    if (close(fd) == -1)
        return (NULL);

    return (data_from_file);
}

int     main(int argc, char ** argv)
{
    if (argc == 2)
        printf("%s\n", get_contents(argv[1]));

    system("leaks -q fdf");

    return (0);
}