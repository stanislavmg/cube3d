#include "types.h"
#include "init.h"

static void	*new_mlx_fail(t_mlx *wm, const char *err);
int	new_img(t_img *img, void *mlx);

t_mlx	*new_mlx(void)
{
	t_mlx	*wm;

	wm = (t_mlx *)ft_calloc(1, sizeof(t_mlx));
	if (!wm)
		return (NULL);
	wm->mlx = mlx_init();
	if (!wm->mlx)
		return (new_mlx_fail(wm, "mlx_init: "));
	wm->win = mlx_new_window(wm->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	if (!wm->win)
		return (new_mlx_fail(wm, "mlx_new_window: "));
	if (new_img(&wm->img, wm->mlx))
		return (new_mlx_fail(wm, "mlx_init_img: "));
	return (wm);
}

int	new_img(t_img *img, void *mlx)
{
	if (!img)
		return (1);
	img->data = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->data)
		return (1);
	img->data_addr = mlx_get_data_addr(
			img->data,
			&img->bits_per_pixel,
			&img->size_line,
			&img->endian);
	if (!img->data_addr)
		return (1);
	return (0);
}

static void	*new_mlx_fail(t_mlx *wm, const char *err)
{
	free_mlx(wm);
	perror(err);
	return (NULL);
}

void	free_mlx(t_mlx *wm)
{
	mlx_destroy_image(wm->mlx, wm->img.data);
	mlx_destroy_window(wm->mlx, wm->win);
	free(wm);
}

// int	events_init(t_mlx *wm)
// {
// 	mlx_hook(fractal->win, KeyPress, KeyPressMask, events_handle, fractal);
// 	//mlx_hook(fractal->win, ButtonPress, ButtonPressMask, mouse_handle, fractal);
// 	mlx_hook(fractal->win,
// 		DestroyNotify,
// 		StructureNotifyMask,
// 		fractal_exit,
// 		fractal);
// 	mlx_hook(fractal->win,
// 		MotionNotify,
// 		PointerMotionMask,
// 		julia_render,
// 		fractal);
// 	return (0);
// }