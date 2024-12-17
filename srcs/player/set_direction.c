/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:29:12 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:29:15 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	set_direction(t_player *player, int dir_key, int len)
{
	if (dir_key == 0)
	{
		player->dir.norm.x = 0;
		player->dir.norm.y = 1;
	}
	else if (dir_key == 1)
	{
		player->dir.norm.x = 0;
		player->dir.norm.y = -1;
	}
	else if (dir_key == 2)
	{
		player->dir.norm.x = -1;
		player->dir.norm.y = 0;
	}
	else if (dir_key == 3)
	{
		player->dir.norm.x = 1;
		player->dir.norm.y = 0;
	}
	player->dir.len = len;
	update_direction(player);
}
