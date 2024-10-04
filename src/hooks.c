#include "types.h"
#include "init.h"

int	hooks_init(t_mlx *wm, t_data *g)
{
	if (!wm || !wm->win || !g)
		return (1);
	if (mlx_hook(wm->win, 2, 1, buttons, g))
		return (1);
	if (mlx_hook(wm->win, ON_DESTROY, 0, exit_game, g))
		return (1);
	return (0);
}
