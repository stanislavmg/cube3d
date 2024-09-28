#include "limits.h"
#include "init.h"

void	draw_frame(t_player *p)
{
	int 	x;
	t_ray	r;
	double	dist;

	if (!p)
		return ;
	x = -1;
	while (++x < WIN_WIDTH)
	{
		r.dir = p->angle + FOV / 2 - x * FOV / WIN_WIDTH;
		r.pos.x = sin(r.dir);
		r.pos.y = cos(r.dir);
		dist = cast_ray(&r.pos, &p->pos);
		draw_vertical_line(&p->wm->img, dist, x);
	}
	mlx_put_image_to_window(p->wm->mlx, p->wm->win, p->wm->img.data, 0, 0);
}

double	cast_ray(t_pos *r, t_pos *p)
{
	int		tx;
	int		ty;
	int		hit;
	double	dist;
	double	deph;
		
	hit = 0;
	dist = 0.0;
	deph = 24;
	if (!r || !p)
		return (0.0);
	while (!hit && dist < deph)
	{
		tx = (int)(p->x + r->x * dist);
        ty = (int)(p->y + r->y * dist);
		dist += RAY_SPEED;
		if (tx < 0 || tx >= deph + p->x || ty < 0 || ty >= deph + p->y)
		{
			hit = 1;
			dist = deph;
		}
		if (worldMap[tx][ty])
			hit = 1;
	}
	return (dist);
}

void	draw_vertical_line(t_img *img, double dist, int x)
{
	int wall;
    int floor;
	int color;
	int y;

	if (!img)
		return ;
	y = -1;
	wall = (int)(WIN_HEIGHT / 2 - WIN_HEIGHT * FOV / dist);
	floor = WIN_HEIGHT - wall;
	while (++y < WIN_HEIGHT)
	{
		if (y <= wall)
			color = BLUE;
		else if (y > wall && y < floor)
			color = GRAY;
		else
			color = GREEN;
		put_pixel(x, y, img, color);
	}
}

void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || y < 0 || !img || color < 0)
		return ;
	offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->data_addr + offset) = color;
}
