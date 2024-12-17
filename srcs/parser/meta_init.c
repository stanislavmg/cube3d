/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:17:17 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 22:03:26 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

t_meta	*meta_init(char **argv)
{
	t_meta	*metadata;

	metadata = (t_meta *)safe_malloc(sizeof(t_meta));
	metadata->fl_txtr = (t_color *)safe_malloc(sizeof(t_color));
	metadata->ce_txtr = (t_color *)safe_malloc(sizeof(t_color));
	metadata->map_str = (char *)safe_malloc(sizeof(char *));
	metadata->maplen = 0;
	metadata->player_pos[0] = -1;
	metadata->txtrs[0] = ft_strdup("NO");
	metadata->txtrs[1] = ft_strdup("SO");
	metadata->txtrs[2] = ft_strdup("WE");
	metadata->txtrs[3] = ft_strdup("EA");
	metadata->txtrs[4] = ft_strdup("F");
	metadata->txtrs[5] = ft_strdup("C");
	metadata->txtrs[6] = ft_strdup("\0");
	if (parser(argv, metadata))
	{
		free_meta(metadata);
		system("leaks cub3D");
		return (NULL);
	}
	system("leaks cub3D");
	return (metadata);
}
