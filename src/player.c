#include "types.h"
#include "init.h"

t_player	*new_player(void)
{
	t_player	*p;

	p = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!p)
		return (NULL);
	p->pos.x = P_START_POSITION;
	p->pos.y = P_START_POSITION;
	p->angle = P_ANGLE_DEFAULT;
	p->move_speed = P_MOVE_SPEED;
	p->rotate_speed = P_ROTATE_SPEED;
	return (p);
}
