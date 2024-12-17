/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:28:37 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:28:39 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	init_player(t_player *player, t_meta *metadata)
{
	player->loc_x = metadata->player_pos[1];
	player->loc_y = metadata->player_pos[0] * -1;
	player->location.x = player->loc_x + 0.5;
	player->location.y = player->loc_y - 0.5;
}
