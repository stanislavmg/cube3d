#include "cub3D.h"

void    free_line(void *obj)
{
    t_line  *line;

    line = (t_line *)obj;
    if (line->start)
        free(line->start);
    if (line->end)
        free(line->end);
    free(line);
}

void    *free_arr(void **arr, void (*free_func)(void *))
{
    void **tmp;

    tmp = arr;
    while (*arr)
    {
       (*free_func)(*arr); 
       arr++;
    }
    free(tmp);
    return (NULL);
}

void    free_grid(t_grid *grid)
{
    if (grid->vert)
        free_arr((void **)grid->vert, free_line);
    if (grid->hor)
        free_arr((void **)grid->hor, free_line);
    free(grid);
}
