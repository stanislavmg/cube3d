/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:11 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:16:13 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"
#include <stdbool.h>

static void	fill_player(t_meta *meta, int y, int x, char view)
{
	meta->player_pos[0] = y;
	meta->player_pos[1] = x;
	if (view == 'N')
		meta->player_pos[2] = 0;
	else if (view == 'S')
		meta->player_pos[2] = 1;
	else if (view == 'W')
		meta->player_pos[2] = 2;
	else if (view == 'E')
		meta->player_pos[2] = 3;
}

static bool	check_founded(char **map, t_meta *meta, int x, int y)
{
	if (map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'E'
		|| map[y][x] == 'S')
	{
		if (meta->player_pos[0] != -1)
		{
			print_error(MULTIPLE_PLAYERS);
			return (false);
		}
		else
			fill_player(meta, y, x, map[y][x]);
	}
	return (true);
}

static int	*check_player(char **map, t_meta *meta)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map && map[y] && map[y][x] && map[y][x] != '\0')
	{
		while (map[y][x] != '\0')
		{
			if (!check_founded(map, meta, x, y))
				return (NULL);
			x++;
		}
		x = 0;
		y++;
	}
	if (meta->player_pos[0] == -1)
	{
		print_error(ZERO_PLAYERS);
		return (NULL);
	}
	return (meta->player_pos);
}

int	check_map(t_meta *meta, char **map)
{
	if (check_player(map, meta) == NULL)
		return (1);
	if (flood_fill(map, meta->player_pos[0], meta->player_pos[1]))
		return (1);
	return (0);
}
