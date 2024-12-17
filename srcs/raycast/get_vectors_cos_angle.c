/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vectors_cos_angle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:31:16 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:31:18 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

double	get_vectors_cos_angle(
	double proj_x, double proj_y, double raydir_x, double raydir_y)
{
	double	scalar;
	double	abs_raydir;
	double	abs_proj_vert;
	double	cos_angle;

	scalar = proj_x * raydir_x + proj_y * raydir_y;
	abs_raydir = sqrt(pow(raydir_x, 2) + pow(raydir_y, 2));
	abs_proj_vert = sqrt(pow(proj_x, 2) + pow(proj_y, 2));
	cos_angle = scalar / abs_raydir / abs_proj_vert;
	return (cos_angle);
}
