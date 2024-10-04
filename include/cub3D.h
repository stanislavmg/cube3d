#ifndef CUB3D
# define CUB3D

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_point{
    double x;
    double y; 
}   t_point;

typedef struct s_line{
    t_point *start;
    t_point *end;
}   t_line;

typedef struct s_grid
{
    t_line  **vert;
    t_line  **hor;
}   t_grid;


# define INCORRECT_COORDS	"Incorrect textures in .cub - check coords\n"
# define INCORRECT_FORMAT	"Incorrect .cub format - leave empty line before FLOOR texture\n"
# define INCORRECT_FILE		"Incorrect file type. Shall be .cub\n"

int     getstrlen(char *str);
t_grid  *get_grid(char **map);

//free.c
void    free_grid(t_grid *grid);
void    free_line(void *line);
void    *free_arr(void **arr, void (*free_func)(void *));
void    print_grid_lines(t_grid *grid);
int		print_error(char *mes);
void	*safe_malloc(size_t str);
bool	ft_isspace(const char a);

#endif