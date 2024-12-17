/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:24:39 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:24:41 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

t_data	*free_data(t_data *g)
{
	free(g->wh);
	free_meta(g->m_data);
	free_mlx(&g->win_mng, g->main_img.data, g->wall[0].img.data);
	free(g->wall);
	free(g);
	return (NULL);
}
