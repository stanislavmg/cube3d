#include "types.h"
#include "init.h"

t_player	new_player(void)
{
	t_player	p;

	p.pos.x = P_START_POSITION;
	p.pos.y = P_START_POSITION;
	p.angle = P_ANGLE_DEFAULT;
	return (p);
}
