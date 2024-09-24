#include "types.h"
#include "init.h"

static void	*new_mlx_fail(t_mlx *wm, const char *err);

t_mlx	*new_mlx(void)
{
	t_mlx	*wm;

	wm = (t_mlx *)malloc(sizeof(wm));
	if (!wm)
		return (NULL);
	wm->mlx = mlx_init();
	if (!wm->mlx)
		return (new_mlx_fail(wm, "mlx_init: "));
	wm->win = mlx_new_window(wm->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!wm->win)
		return (new_mlx_fail(wm, "mlx_new_window: "));
	wm->img.data = mlx_new_image(wm->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!wm->img.data)
		return (new_mlx_fail(wm, "mlx_new_image: "));
	wm->img.data_addr = mlx_get_data_addr(
			wm->img.data,
			&wm->img.bits_per_pixel,
			&wm->img.size_line,
			&wm->img.endian);
	if (!wm->img.data_addr)
		return (new_mlx_fail(wm, "mlx_get_data_addr:"));
	return (wm);
}

static void	*new_mlx_fail(t_mlx *wm, const char *err)
{
	mlx_destroy_image(wm->mlx, wm->img.data);
	mlx_destroy_window(wm->mlx, wm->win);
	free(wm);
	perror(err);
	return (NULL);
}