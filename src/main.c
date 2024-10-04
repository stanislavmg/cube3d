#include "types.h"
#include "init.h"

char *worldMap[] =
{
  "111111111111111111111111", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000001111111100000001", 
  "100000000000000100000001", 
  "100000000000000100000001", 
  "100000000000000100000001", 
  "100000001111111100000001", 
  "100000000000000000000001", 
  "100000000101010100000001", 
  "100000000000000000000001", 
  "100000000101010100000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "100000000000000000000001", 
  "111111111111111111111111", 
  NULL
};

void  free_text(void *mlx, t_text *arr, size_t size)
{
  size_t  i;
  
  i = 0;
  while (i < size)
  {
    mlx_destroy_image(mlx, arr[i].img.data);
    i++;
  }
}

t_data *free_game_data(t_data *game)
{
  free_grid(game->map_grid);
  mlx_destroy_image(&game->win_mng, game->main_img.data);
  free_mlx(&game->win_mng);
  free(game);
  return (NULL);
}

t_data *init_game_data(char **map)
{
  t_data  *data;

  data = ft_calloc(1, sizeof(t_data));
  if (!data)
    return (NULL);
  data->map_grid = get_grid(map);
  if (!data->map_grid)
    return (free_game_data(data));
  data->win_mng = new_mlx();
  data->p = new_player();
  data->main_img = new_img(data->win_mng.mlx, WIN_WIDTH, WIN_HEIGHT);
  data->wall[0].img.data = mlx_xpm_file_to_image(data->win_mng.mlx,
                                                "texture/greystone.xpm",
                                                &data->wall[0].width,
                                                &data->wall[0].height);
  data->wall[0].img.data_addr = mlx_get_data_addr(data->wall[0].img.data,
                                                  &data->wall[0].img.bits_per_pixel,
                                                  &data->wall[0].img.size_line,
                                                  &data->wall[0].img.endian);
  if (!data->wall[0].img.data_addr)
    return(free_game_data(data));
  return (data);
}

int	main(int ac, char **av)
{
  t_data  *game;

  (void)ac;
  (void)av;
  game = init_game_data(worldMap);
  if (!game)
    return (1);
	draw_frame(game);
	hooks_init(&game->win_mng, game);
	mlx_loop(game->win_mng.mlx);
	mlx_loop_hook(game->win_mng.mlx, buttons, game);
	return (0);
}
