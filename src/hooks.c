#include "types.h"
#include "init.h"

int	hooks_init(t_mlx *wm, t_player *p)
{
	if (!wm || !wm->win || !p)
		return (-1);
	mlx_hook(wm->win, 2, 1, buttons, p);
	mlx_hook(wm->win, ON_DESTROY, 0, mlx_exit, p);
	return (0);
}

double get_current_time() 
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec + (time.tv_usec / 1000000.0));
}

int	buttons(int keysym, t_player *p)
{
	static double prev_time = 0;;
	double	delta;
	double	cur_time;
	double	fps = 1.0 / FPS;

	if (keysym < 0 || !p)
		return (1);
	cur_time = get_current_time();
	if (prev_time == 0)
        prev_time = cur_time;
	delta = cur_time - prev_time;
	if (delta > fps)
		delta = fps;
	if (keysym == KEY_ESC)
	{
		free_mlx(p->wm);
		exit(0);
	}
	else if (keysym == KEY_W)
	{
		double new_posX = p->pos.x + sin(p->angle) * p->move_speed * delta;
		double new_posY = p->pos.y + cos(p->angle) * p->move_speed * delta;
		if (!worldMap[(int)new_posX][(int)new_posY]){
			p->pos.x = new_posX;
			p->pos.y = new_posY;
		}
	}
	else if (keysym == KEY_D)
	{
		double new_posX = p->pos.x - sin(p->angle + PI / 2) * p->move_speed * delta;
		double new_posY = p->pos.y - cos(p->angle + PI / 2) * p->move_speed * delta;
		if (!worldMap[(int)new_posX][(int)new_posY]){
			p->pos.x = new_posX;
			p->pos.y = new_posY;
		}
	}
	else if (keysym == KEY_S)
	{
		double new_posX = p->pos.x - sin(p->angle) * p->move_speed * delta;
		double new_posY = p->pos.y - cos(p->angle) * p->move_speed * delta;
		if (!worldMap[(int)new_posX][(int)new_posY]){
			p->pos.x = new_posX;
			p->pos.y = new_posY;
		}
	}
	else if (keysym == KEY_A)
	{
		double new_posX = p->pos.x + sin(p->angle + PI / 2) * p->move_speed * delta;
		double new_posY = p->pos.y + cos(p->angle + PI / 2) * p->move_speed * delta;
		if (!worldMap[(int)new_posX][(int)new_posY]){
			p->pos.x = new_posX;
			p->pos.y = new_posY;
		}
	}
	else if (keysym == KEY_ARROW_LEFT)
		p->angle += p->rotate_speed * delta;
	else if (keysym == KEY_ARROW_RIGHT)
		p->angle -= p->rotate_speed * delta;
	if (p->angle < 0)
		p->angle += 2 * PI;
	if (p->angle >= 2 * PI)
		p->angle -= 2 * PI;
	draw_frame(p);
	prev_time = cur_time;
	return (0);
}
