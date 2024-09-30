#include "types.h"
#include "init.h"

int	hooks_init(t_mlx *wm, t_player *p)
{
	if (!wm || !wm->win || !p)
		return (1);
	if (mlx_hook(wm->win, 2, 1, buttons, p))
		return (1);
	if (mlx_hook(wm->win, ON_DESTROY, 0, mlx_exit, p))
		return (1);
	return (0);
}

double get_current_time() 
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec + (time.tv_usec / 1000000.0));
}

static double	get_delta_time()
{
	static double	prev_time = 0;
	double			delta;
	double			cur_time;

	cur_time = get_current_time();
	if (prev_time == 0)
        prev_time = cur_time;
	delta = cur_time - prev_time;
	if (delta > 1.0 / FPS)
		delta = 1.0 / FPS;
	prev_time = cur_time;
	return (delta);
}

int	buttons(int keysym, t_player *p)
{
	double	delta;
	double	factor;
	t_pos	new_pos;

	if (keysym < 0 || !p)
		return (1);
	ft_memset(&new_pos, 0, sizeof(t_pos));
	delta = get_delta_time();
	factor = delta * p->move_speed;
	if (keysym == KEY_ESC)
	{
		free_mlx(p->wm);
		exit(0);
	}
	else if (keysym == KEY_W)
		new_pos = pos_sum(p->pos, calc_new_pos(p->angle, factor));
	else if (keysym == KEY_D)
		new_pos = pos_sub(p->pos, calc_new_pos(p->angle + PI / 2, factor));
	else if (keysym == KEY_S)
		new_pos = (pos_sub(p->pos, calc_new_pos(p->angle, factor)));
	else if (keysym == KEY_A)
		new_pos = (pos_sum(p->pos, calc_new_pos(p->angle + PI / 2, factor)));
	else if (keysym == KEY_ARROW_LEFT)
		p->angle += p->rotate_speed * delta;
	else if (keysym == KEY_ARROW_RIGHT)
		p->angle -= p->rotate_speed * delta;
	if (p->angle < 0)
		p->angle += 2 * PI;
	if (p->angle >= 2 * PI)
		p->angle -= 2 * PI;
	if (!worldMap[(int)new_pos.x][(int)new_pos.y])
		p->pos = new_pos;
	draw_frame(p);
	return (0);
}
