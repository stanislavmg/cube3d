/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:09:27 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 22:09:29 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	print_grid_lines(t_grid *grid)
{
	int	i;

	i = 0;
	while (grid->vert[i])
	{
		printf("start x - %f, start y - %f\nend x - %f, end y - %f\n",
			grid->vert[i]->start.x, grid->vert[i]->start.y,
			grid->vert[i]->end.x, grid->vert[i]->end.y);
		i++;
	}
}

void	print_metadata(t_meta *meta)
{
	char	**tmp;

	tmp = meta->map;
	if (meta->map && meta->map[0])
		printf("MAP EXIST\n");
	else
		printf("MAP NOT EXIST\n");
	while (*tmp)
	{
		printf("LINE %s\n", *tmp);
		tmp++;
	}
}
