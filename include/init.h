#ifndef INIT_H
#define INIT_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "types.h"
#include "libft.h"

t_mlx	*new_mlx(void);

/*** render ***/
void	put_pixel(int x, int y, t_img *img, int color);
void	render(t_mlx *wm);
void	free_mlx(t_mlx *wm);
void	draw_tile(t_img *img, const t_pos *map, int color);
void	draw_player(t_player *p);
void	cast_rays(t_player *p);

/*** hooks ***/
int	hooks_init(t_mlx *wm, t_player *p);
int	buttons(int keysym, t_player *p);
int	mlx_exit(t_mlx *wm);

#endif