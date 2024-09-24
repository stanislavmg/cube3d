#include "types.h"
#include "init.h"

int	map[8][8] = 
{ 
{1, 1, 1, 1, 1, 1, 1, 1 },
{1, 0, 0, 0, 1, 0, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 1 },
{1, 0, 0, 0, 1, 0, 0, 1 },
{1, 0, 0, 0, 0, 0, 0, 1 },
{1, 0, 1, 0, 0, 0, 0, 1 },
{1, 0, 1, 0, 0, 0, 0, 1 },
{1, 1, 1, 1, 1, 1, 1, 1 }
};

void	draw_player(t_player *p)
{
	(void)p;
}

void	draw_map()
{

}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_mlx	*wm;

	wm = new_mlx();
	(void)wm;
	//mlx_put_image_to_window(wm.mlx, wm.win, wm.img.data, 1, 1);
	while(1);
	//mlx_destroy_window(wm.mlx, wm.win);
	return (0);
}


