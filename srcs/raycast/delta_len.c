/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:30:35 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:30:36 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

double	delta_len(int index, t_point ray)
{
	double	proj_x;
	double	proj_y;
	double	cos_angle;

	if (index)
	{
		if (ray.x < 0)
			proj_x = -1;
		else
			proj_x = 1;
		proj_y = 0;
	}
	else
	{
		if (ray.y < 0)
			proj_y = -1;
		else
			proj_y = 1;
		proj_x = 0;
	}
	cos_angle = get_vectors_cos_angle(proj_x, proj_y, ray.x, ray.y);
	return (1 / cos_angle);
}
