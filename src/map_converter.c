#include "cub3D.h"

int getstrlen(char *str){
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

static int arr_len(void **arr){
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

static int str_max_len(void **arr)
{
    int max_len;
    int i;
    int cur_len;
    
    i = 0;
    max_len = 0;
    while (arr[i])
    {
        cur_len = getstrlen(arr[i]);  
        if (cur_len > max_len)
            max_len = cur_len;
        i++;
    }
    return (max_len);
}

static void setup_line_bounds(int is_vert, t_line *line, int i, double max_len)
{
    if (is_vert)
    {
        line->start->x = i;
        line->start->y = 0;
        line->end->x = i;
        line->end->y = max_len;
    }
    else
    {
        line->start->x = 0;
        line->start->y = i;
        line->end->x = max_len;
        line->end->y = i;
    }
}

static t_line   **get_parallel_line_arr(int line_num, double max_len, int is_vert)
{
    t_line  **line_arr;
    int     i;

    line_arr = (t_line **)malloc(sizeof(t_line *) * (line_num + 1));
    if (!line_arr)
        return (NULL);
    i = 0;
    while (i < line_num)
    {
        line_arr[i] = (t_line *)malloc(sizeof(t_line));
        if (!line_arr[i])
            return (free_arr((void **)line_arr, free_line));
        line_arr[i]->start = (t_point *)malloc(sizeof(t_point));
        line_arr[i]->end = (t_point *)malloc(sizeof(t_point));
        if (!(line_arr[i]->start) || !(line_arr[i]->end))
            return (free_arr((void **)line_arr, free_line));
        setup_line_bounds(is_vert, line_arr[i], i, max_len);
        i++;
    }
    line_arr[line_num] = NULL;
    return (line_arr);
}

t_grid  *get_grid(char **map)
{   
    t_grid  *grid;
    int vert_num;
    int hor_num;

    hor_num = arr_len((void **)map) + 1;
    vert_num = str_max_len((void **)map) + 1;
    grid = (t_grid *)malloc(sizeof(t_grid));
    if (!grid)
        return (NULL);
    grid->vert = get_parallel_line_arr(vert_num, hor_num, 1);
    grid->hor = get_parallel_line_arr(hor_num, vert_num, 0);
    if (!grid->vert || !grid->hor)
    {
        free_grid(grid);
        return (NULL);
    }
    return (grid);
}