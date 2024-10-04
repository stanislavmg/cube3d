#include "types.h"
#include "init.h"

t_mlx	new_mlx(void)
{
	t_mlx	wm;

	ft_memset(&wm, 0, sizeof(t_mlx));
	wm.mlx = mlx_init();
	if (!wm.mlx)
		return (wm);
	wm.win = mlx_new_window(wm.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	return (wm);
}

t_img	new_img(void *mlx, int w, int h)
{
	t_img	i;

	ft_memset(&i, 0, sizeof(t_img));
	i.data = mlx_new_image(mlx, w, h);
	if (!i.data)
		return (i);
	i.data_addr = mlx_get_data_addr(
			i.data,
			&i.bits_per_pixel,
			&i.size_line,
			&i.endian);
	if (!i.data_addr)
	{
		mlx_destroy_image(mlx, i.data);
		i.data = NULL;
	}
	return (i);
}

void	free_mlx(t_mlx *wm)
{
	if (!wm)
		return ;
	mlx_destroy_window(wm->mlx, wm->win);
}

int mlx_exit(t_data *game)
{
	free_game_data(game);
	exit(0);
}
