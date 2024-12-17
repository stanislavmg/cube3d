/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:29:24 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:29:25 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	set_fov(t_vector *dir, t_fov *fov, int screen_width, double fov_width)
{
	double	start_x;
	double	start_y;
	double	end_x;
	double	end_y;

	fov->width = fov_width;
	start_x = dir->norm.y * -1;
	start_y = dir->norm.x;
	end_x = dir->norm.y;
	end_y = dir->norm.x * -1;
	fov->start.x = dir->val.x + (start_x * fov->width / 2);
	fov->start.y = dir->val.y + (start_y * fov->width / 2);
	fov->end.x = dir->val.x + (end_x * fov->width / 2);
	fov->end.y = dir->val.y + (end_y * fov->width / 2);
	fov->iter_x = (fov->end.x - fov->start.x) / screen_width;
	fov->iter_y = (fov->end.y - fov->start.y) / screen_width;
}
