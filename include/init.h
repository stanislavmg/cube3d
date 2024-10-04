#ifndef INIT_H
#define INIT_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <sys/time.h>
#include "mlx.h"
#include "libft.h"
#include "types.h"

extern char *worldMap[];

void	    free_mlx(t_mlx *wm);
double		get_current_time();
double		get_delta_time();
int			exit_game(t_data *data);
int 		mlx_exit(t_data *game);
t_player	new_player(void);
t_mlx		new_mlx(void);
t_img		new_img(void *mlx, int w, int h);
void		free_mlx(t_mlx *wm);
t_data		*free_game_data(t_data *game);

/*** render ***/
double	cast_ray(t_pos *r, t_pos *p);
//void	draw_vertical_line(t_text *t, t_img *img, double dist, int x);
void	put_pixel(int x, int y, t_img *img, int color);
void	draw_frame(t_data *g);

/*** hooks ***/
int	hooks_init(t_mlx *wm, t_data *g);
int	buttons(int keysym, t_data *g);

/*** t_pos operation ***/
t_pos	pos_sub(const t_pos a, const t_pos b);
t_pos	pos_sum(const t_pos a, const t_pos b);



#endif