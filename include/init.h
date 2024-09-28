#ifndef INIT_H
#define INIT_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <sys/time.h>
#include "mlx.h"
#include "types.h"
#include "libft.h"

extern int worldMap[mapHeight][mapWidth];

t_mlx       *new_mlx(void);
t_player	*new_player(void);
void	    free_mlx(t_mlx *wm);
double get_current_time();

/*** render ***/
void	draw_frame(t_player *p);
double	cast_ray(t_pos *r, t_pos *p);
void	draw_vertical_line(t_img *img, double dist, int x);
void	put_pixel(int x, int y, t_img *img, int color);

void	draw_tile(t_img *img, const t_pos *map, int color);

/*** hooks ***/
int	hooks_init(t_mlx *wm, t_player *p);
int	buttons(int keysym, t_player *p);
int	mlx_exit(t_mlx *wm);

#endif