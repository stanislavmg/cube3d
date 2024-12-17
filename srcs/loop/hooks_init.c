/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:27:30 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 21:08:12 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

int	hooks_init(t_mlx *wm, t_data *g)
{
	if (!wm || !wm->win || !g)
		return (1);
	mlx_hook(wm->win, ON_KEYDOWN, KEY_PRESS_MASK, on_key_pressed, g);
	mlx_hook(wm->win, ON_DESTROY, DESTROY_MASK, exit_game, g);
	return (0);
}
