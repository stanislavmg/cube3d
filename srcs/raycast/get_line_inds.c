/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_inds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:31:00 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:31:02 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static void	set_x(t_point dir, int loc_cell_x, int *indexes, t_point location)
{
	double	loc_x;

	if (dir.x > 0)
		indexes[1] = loc_cell_x + 1;
	else if (dir.x < 0)
	{
		indexes[1] = loc_cell_x;
		if (modf(location.x, &loc_x) == 0)
			indexes[1]--;
	}
}

static void	set_y(t_point dir, int loc_cell_y, int *indexes, t_point location)
{
	double	loc_y;

	if (dir.y > 0)
	{
		indexes[0] = loc_cell_y;
		if (modf(location.y, &loc_y) == 0)
			indexes[0]++;
	}
	else if (dir.y < 0)
		indexes[0] = loc_cell_y - 1;
}

int	get_line_inds(int *indexes, t_point location, t_point dir)
{
	int		loc_cell_x;
	int		loc_cell_y;

	loc_cell_x = location.x / 1;
	loc_cell_y = location.y / 1;
	if (dir.x == 0 && dir.y == 0)
		return (0);
	if (dir.x == 0)
		indexes[1] = -1;
	if (dir.y == 0)
		indexes[0] = -1;
	set_x(dir, loc_cell_x, indexes, location);
	set_y(dir, loc_cell_y, indexes, location);
	return (1);
}
