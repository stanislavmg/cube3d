#include "types.h"
#include "init.h"

int	hooks_init(t_mlx *wm, t_player *p)
{
	mlx_hook(wm->win, 2, 1, buttons, p);
	//mlx_hook(wm->win, ButtonPress, 0, mouse_handle, wm);
	mlx_hook(wm->win, ON_DESTROY, 0, mlx_exit, p);
	//mlx_hook(wm->win, MotionNotify, 0, julia_render, wm);
	return (0);
}

int	buttons(int keysym, t_player *p)
{

	if (keysym < 0 || !p)
		return (1);
	if (keysym == KEY_ESC)
	{
		free_mlx(p->wm);
		exit(0);
	}
	else if (keysym == KEY_W)
	{
		p->pos.x += sin(p->angle) * p->move_speed;
		p->pos.y += cos(p->angle) * p->move_speed;
	}
	else if (keysym == KEY_A){
		double strafe_angle = p->angle - PI / 2;
		p->pos.x += cos(strafe_angle) * p->move_speed;
		p->pos.y += sin(strafe_angle) * p->move_speed;	
	}
	else if (keysym == KEY_S)
	{
		p->pos.x -= sin(p->angle) * p->move_speed;
		p->pos.y -= cos(p->angle) * p->move_speed;
	}
	else if (keysym == KEY_D){
		double strafe_angle = p->angle - PI / 2;
		p->pos.x -= cos(strafe_angle) * p->move_speed;
		p->pos.y -= sin(strafe_angle) * p->move_speed;
	}
	else if (keysym == KEY_ARROR_LEFT)
		p->angle += 0.1 * p->rotate_speed;
	else if (keysym == KEY_ARROR_RIGHT)
		p->angle -= 0.1 * p->rotate_speed;
	cast_rays(p);
	return (0);
}

int mlx_exit(t_mlx *wm)
{
	free_mlx(wm);
	exit(0);
}

// int	mouse_handle(int keysym, int x, int y, t_fractol *wm)
// {
// 	(void)x;
// 	(void)y;
// 	if (keysym == Button4)
// 		wm->factor *= 0.95;
// 	else if (keysym == Button5)
// 		wm->factor *= 1.05;
// 	wm_render(wm);
// 	return (0);
// }