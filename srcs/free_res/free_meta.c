/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_meta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:24:55 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:24:57 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	free_meta(t_meta *meta)
{
	int	i;

	i = 0;
	if (meta->no_txtr)
		free(meta->no_txtr);
	if (meta->so_txtr)
		free(meta->so_txtr);
	if (meta->ea_txtr)
		free(meta->ea_txtr);
	if (meta->we_txtr)
		free(meta->we_txtr);
	if (meta->fl_txtr)
		free(meta->fl_txtr);
	if (meta->ce_txtr)
		free(meta->ce_txtr);
	if (meta->map)
		free_arr((void **)meta->map, free);
	while (i <= 6)
		free(meta->txtrs[i++]);
	free(meta->map_str);
	free(meta);
}
