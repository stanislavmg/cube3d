/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:31:51 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:31:53 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static t_vector	set_ray(double raypoint_x, double raypoint_y, t_player *player)
{
	t_vector	ray;

	ray.val.x = raypoint_x - player->location.x;
	ray.val.y = raypoint_y - player->location.y;
	return (ray);
}

static void	update_ray(t_vector *ray)
{
	ray->len = sqrt(pow(ray->val.x, 2) + pow(ray->val.y, 2));
	ray->norm.x = ray->val.x / ray->len;
	ray->norm.y = ray->val.y / ray->len;
}

static void	fill_calc_data(
	t_calc *calc_data, t_vector *ray, t_player *player, int *line_inds)
{
	calc_data[0].is_vert = 1;
	calc_data[0].orients[0] = 'e';
	calc_data[0].orients[1] = 'w';
	calc_data[0].len_delta = delta_len(1, ray->val);
	calc_data[0].wall_face_dir = ray->val.x;
	calc_data[0].ray_hit = ray_hit_len(line_inds, 1, player, ray);
	calc_data[1].is_vert = 0;
	calc_data[1].orients[0] = 's';
	calc_data[1].orients[1] = 'n';
	calc_data[1].len_delta = delta_len(0, ray->val);
	calc_data[1].wall_face_dir = ray->val.y;
	calc_data[1].ray_hit = ray_hit_len(line_inds, 0, player, ray);
}

static void	fill_wallhit(t_wallhit *hit, t_calc calc_data)
{
	double	i;

	hit->distance = calc_data.ray_hit.len;
	hit->hit = calc_data.ray_hit.norm;
	if (calc_data.wall_face_dir < 0)
		hit->orientation = calc_data.orients[0];
	else
		hit->orientation = calc_data.orients[1];
	if (calc_data.is_vert)
		hit->offset = modf(calc_data.ray_hit.val.y, &i);
	else
		hit->offset = modf(calc_data.ray_hit.val.x, &i);
	hit->is_vert = calc_data.is_vert;
}

int	raycast(t_player *player, t_wallhit *hits, int scr_width, char **map)
{
	int			i;
	t_vector	ray;
	t_calc		calc_data[2];
	int			line_inds[2];
	t_calc		target;

	ray = set_ray(player->fov.start.x, player->fov.start.y, player);
	i = 0;
	while (i < scr_width)
	{
		update_ray(&ray);
		if (!get_line_inds(line_inds, player->location, ray.val))
			return (0);
		fill_calc_data(calc_data, &ray, player, line_inds);
		target = find_wall(calc_data, player->location, map);
		fill_wallhit(&(hits[i]), target);
		ray.val.x += player->fov.iter_x;
		ray.val.y += player->fov.iter_y;
		i++;
	}
	return (1);
}
