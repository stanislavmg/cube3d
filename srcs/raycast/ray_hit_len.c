/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:31:32 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:31:34 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

t_vector	ray_hit_len(
	int *line_inds, int index, t_player *player, t_vector *ray)
{
	double		proj_x;
	double		proj_y;
	double		proj_len;
	double		cos_angle;
	t_vector	ray_hit;

	if (index)
	{
		proj_x = line_inds[index] - player->location.x;
		proj_y = 0;
		proj_len = fabs(proj_x);
	}
	else
	{
		proj_x = 0;
		proj_y = line_inds[index] - player->location.y;
		proj_len = fabs(proj_y);
	}
	cos_angle = get_vectors_cos_angle(proj_x, proj_y, ray->norm.x, ray->norm.y);
	ray_hit.len = proj_len / cos_angle;
	ray_hit.norm.x = ray->norm.x;
	ray_hit.norm.y = ray->norm.y;
	ray_hit.val.x = player->location.x + ray->norm.x * ray_hit.len;
	ray_hit.val.y = player->location.y + ray->norm.y * ray_hit.len;
	return (ray_hit);
}
