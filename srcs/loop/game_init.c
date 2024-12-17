/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:27:07 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:27:08 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static t_mlx	new_mlx(void);
static t_img	new_img(void *mlx, int w, int h);
static void		init_img(t_data *game);

t_data	*game_init(t_meta *metadata)
{
	t_data	*game;

	game = (t_data *)safe_malloc(sizeof(t_data));
	if (!game)
		return (NULL);
	game->wh = (t_wallhit *)safe_malloc(sizeof(t_wallhit) * (WIN_WIDTH + 1));
	if (!game->wh)
		return (free_data(game));
	init_player(&game->player, metadata);
	set_direction(&game->player, metadata->player_pos[2], 3);
	set_fov(&game->player.dir, &game->player.fov, WIN_WIDTH, 5);
	game->win_mng = new_mlx();
	game->main_img = new_img(game->win_mng.mlx, WIN_WIDTH, WIN_HEIGHT);
	game->wall = malloc(sizeof(t_text) * 4);
	game->m_data = metadata;
	init_img(game);
	raycast(&game->player, game->wh, WIN_WIDTH, game->m_data->map);
	return (game);
}

static t_mlx	new_mlx(void)
{
	t_mlx	wm;

	ft_memset(&wm, 0, sizeof(t_mlx));
	wm.mlx = mlx_init();
	if (!wm.mlx)
		return (wm);
	wm.win = mlx_new_window(wm.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	return (wm);
}

static t_img	new_img(void *mlx, int w, int h)
{
	t_img	i;

	ft_memset(&i, 0, sizeof(t_img));
	i.data = mlx_new_image(mlx, w, h);
	if (!i.data)
		return (i);
	i.data_addr = mlx_get_data_addr(
			i.data,
			&i.bits_per_pixel,
			&i.size_line,
			&i.endian);
	if (!i.data_addr)
	{
		mlx_destroy_image(mlx, i.data);
		printf("mlx_get_data_addr: error\n");
		i.data = NULL;
	}
	return (i);
}

static void	init_img(t_data *game)
{
	int		i;
	char	**paths;

	paths = (char **)malloc(sizeof(char *) * 4);
	paths[0] = game->m_data->no_txtr;
	paths[1] = game->m_data->so_txtr;
	paths[2] = game->m_data->we_txtr;
	paths[3] = game->m_data->ea_txtr;
	i = -1;
	while (++i < 4)
	{
		game->wall[i].img.data = mlx_xpm_file_to_image(
				game->win_mng.mlx,
				paths[i],
				&game->wall[i].width,
				&game->wall[i].height);
		game->wall[i].img.data_addr = mlx_get_data_addr(
				game->wall[i].img.data,
				&game->wall[i].img.bits_per_pixel,
				&game->wall[i].img.size_line,
				&game->wall[i].img.endian);
	}
	free(paths);
}
