#include "types.h"
#include "init.h"

t_pos	calc_new_pos(double angle, double factor)
{
	t_pos	new_pos;

	new_pos.x = sin(angle) * factor;
	new_pos.y = cos(angle) * factor;
	return (new_pos);
}

t_pos	pos_sub(const t_pos a, const t_pos b)
{
	t_pos	res;
	
	res.x = a.x - b.x;
	res.y = a.y - b.y;
	return (res);
}

t_pos	pos_sum(const t_pos a, const t_pos b)
{
	t_pos	res;
	
	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}
