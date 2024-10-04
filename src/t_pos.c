#include "types.h"
#include "init.h"



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
