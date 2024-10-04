#include "init.h"
#include "types.h"

double get_current_time() 
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec + (time.tv_usec / 1000000.0));
}

double	get_delta_time()
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

int	exit_game(t_data *data)
{
	free_game_data(data);
	exit(0);
}
