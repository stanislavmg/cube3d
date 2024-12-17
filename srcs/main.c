/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:20:24 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:20:26 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	*game;
	t_meta	*metadata;

	if (argc < 2)
		return (print_error("No .cub file provided!\n"));
	metadata = meta_init(argv);
	if (!metadata)
		return (1);
	game = game_init(metadata);
	if (!game)
		return (1);
	hooks_init(&game->win_mng, game);
	draw_frame(game);
	mlx_loop(game->win_mng.mlx);
	free_data(game);
	return (0);
}
