/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:25:10 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:25:26 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	free_mlx(t_mlx *wm, void *main_img, void *text)
{
	if (!wm)
		return ;
	mlx_destroy_image(wm->mlx, main_img);
	mlx_destroy_image(wm->mlx, text);
	mlx_destroy_window(wm->mlx, wm->win);
}
