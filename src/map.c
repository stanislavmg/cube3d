#include "types.h"
#include "init.h"



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
