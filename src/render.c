#include "limits.h"
#include "init.h"

/*double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}*/

void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || y < 0 || !img || color < 0)
		return ;
	offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->data_addr + offset) = color;
}

void	render(t_mlx *wm)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			put_pixel(x, y, &wm->img, GRAY);
		}
	}
	mlx_put_image_to_window(wm->mlx,
		wm->win,
		wm->img.data, 0, 0);
}
