#include "types.h"
#include "init.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	draw_tile(t_img *img, const t_pos *map, int color)
{
	t_pos	tile;
	int		tile_w;
	int		tile_h;
	int		offset_x;
	int		offset_y;

	tile.y = -1;
	tile_w = WIN_WIDTH / mapWidth;
	tile_h = WIN_HEIGHT / mapHeight;
	offset_x = map->x * tile_w;
	offset_y = map->y * tile_h;
	while (++tile.y < tile_h)
	{
		tile.x = -1;
		while (++tile.x < tile_w)
            put_pixel(tile.x + offset_x, tile.y + offset_y, img, color);
	}
}

void	draw_map(t_mlx *wm)
{
	t_pos	map;
	
	map.y = -1;
	while (++map.y < mapHeight)
	{
		map.x = -1;
		while (++map.x < mapWidth)
		{
			if (worldMap[(int)map.y][(int)map.x])
				draw_tile(&wm->img, &map, 0);
		}
	}
	mlx_put_image_to_window(wm->mlx, wm->win, wm->img.data, 0, 0);
}

t_player	*new_player(void)
{
	t_player	*p;

	p = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!p)
		return (NULL);
	p->pos.x = 5.0;
	p->pos.y = 5.0;
	p->angle = 90;
	p->move_speed = 0.1;
	p->rotate_speed = 0.5;
	return (p);
}

void	cast_rays(t_player *p)
{
	int x;
	double		d[WIN_WIDTH];

	x = -1;
	while (++x < WIN_WIDTH)
	{
		t_ray	r;
		int		hit;
		double	dist;
		double	deph;
		
		hit = 0;
		dist = 0.0;
		deph = 24;
		r.dir = p->angle + FOV / 2 - x * FOV / WIN_WIDTH;
		r.pos.x = sin(r.dir);
		r.pos.y = cos(r.dir);

		while (!hit && dist < deph)
		{
			int tx = (int)(p->pos.x + r.pos.x * dist);
            int ty = (int)(p->pos.y + r.pos.y * dist);

			dist += RAY_SPEED;
			if (tx < 0 || tx >= deph + p->pos.x || ty < 0 || ty >= deph + p->pos.y)
			{
				hit = 1;
				dist = deph;
			}
			if (worldMap[tx][ty])
				hit = 1;
		}
		d[x] = dist;
		int wall = (int)(WIN_HEIGHT / 2 - WIN_HEIGHT * FOV / dist);
	    int floor = WIN_HEIGHT - wall;
		int y = -1;
		int color = 0;

		while (++y < WIN_HEIGHT)
		{
			if (y < wall)
				color = 0;
			else if (y > wall && y < floor)
				color = GRAY;
			else
				color = 0;
			put_pixel(x, y, &p->wm->img, color);
		}
	}
	mlx_put_image_to_window(p->wm->mlx, p->wm->win, p->wm->img.data, 0, 0);
}
			

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_mlx	*wm;
	t_player *p;

	wm = new_mlx();
	if (!wm)
		return (1);
	p = new_player();
	if (!p)
		return (1);
	p->wm = wm;
	render(wm);
	//draw_map(wm);
	cast_rays(p);
	hooks_init(wm, p);
	mlx_loop(wm->mlx);
	mlx_loop_hook(wm->mlx, buttons, p);
	return (0);
}
