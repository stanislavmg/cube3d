#include "types.h"
#include "init.h"

static t_pos	get_new_pos(const t_player *p, int keysym, double delta);
static t_pos	calc_new_pos(double angle, double factor);

int	buttons(int keysym, t_data *g)
{
	double	delta;
	t_pos	new_pos;
	t_player *p;

	if (keysym < 0 || !g)
		return (1);
	delta = get_delta_time();
	p = &g->p;
	ft_memset(&new_pos, 0, sizeof(t_pos));
	if (keysym == KEY_ESC)
		exit_game(g);
	else if (keysym == KEY_ARROW_LEFT)
		p->angle += P_ROTATE_SPEED * delta;
	else if (keysym == KEY_ARROW_RIGHT)
		p->angle -= P_ROTATE_SPEED * delta;
	else
		new_pos = get_new_pos(p, keysym, delta);
	if (worldMap[(int)new_pos.x][(int)new_pos.y] != '1')
		p->pos = new_pos;
	if (p->angle < 0)
		p->angle += 2 * PI;
	if (p->angle >= 2 * PI)
		p->angle -= 2 * PI;
	draw_frame(g);
	return (0);
}

static t_pos	get_new_pos(const t_player *p, int keysym, double delta)
{
	t_pos	new_pos;
	double	factor;

	factor = P_MOVE_SPEED * delta;
	ft_memset(&new_pos, 0, sizeof(t_pos));
	if (keysym == KEY_W)
		new_pos = pos_sum(p->pos, calc_new_pos(p->angle, factor));
	else if (keysym == KEY_D)
		new_pos = pos_sub(p->pos, calc_new_pos(p->angle + PI / 2, factor));
	else if (keysym == KEY_S)
		new_pos = (pos_sub(p->pos, calc_new_pos(p->angle, factor)));
	else if (keysym == KEY_A)
		new_pos = (pos_sum(p->pos, calc_new_pos(p->angle + PI / 2, factor)));
	return(new_pos);	
}

static t_pos	calc_new_pos(double angle, double factor)
{
	t_pos	new_pos;

	new_pos.x = sin(angle) * factor;
	new_pos.y = cos(angle) * factor;
	return (new_pos);
}
