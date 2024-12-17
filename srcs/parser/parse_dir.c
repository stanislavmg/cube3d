/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:17:41 by defimova          #+#    #+#             */
/*   Updated: 2024/11/07 17:24:02 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static bool	is_txtrs_not_valid(char **txtrs_arr)
{
	return (!txtrs_arr || !txtrs_arr[0] || txtrs_arr[0][0] == '\0'
		|| !txtrs_arr[1] || txtrs_arr[1][0] == '\0' || (txtrs_arr
			&& txtrs_arr[2] && txtrs_arr[2][0] != '\0'));
}

static int	check_txtr_input(char *ln, char **txtrs, t_meta *meta)
{
	char	**txtrs_arr;
	int		i;

	i = 0;
	txtrs_arr = ft_split(ln, ' ');
	if (is_txtrs_not_valid(txtrs_arr))
	{
		free_arr((void **)txtrs_arr, free);
		return (1);
	}
	while (txtrs[i])
	{
		if (!ft_strcmp(txtrs_arr[0], txtrs[i++]))
		{
			if (fill_wall(txtrs_arr, meta))
			{
				free_arr((void **)txtrs_arr, free);
				return (1);
			}
			free_arr((void **)txtrs_arr, free);
			return (0);
		}
	}
	free_arr((void **)txtrs_arr, free);
	return (0);
}

static int	check_full_txtrs(t_meta *meta)
{
	if (!meta->no_txtr || meta->no_txtr[0] == '\0')
		return (0);
	if (!meta->so_txtr || meta->so_txtr[0] == '\0')
		return (0);
	if (!meta->we_txtr || meta->we_txtr[0] == '\0')
		return (0);
	if (!meta->ea_txtr || meta->ea_txtr[0] == '\0')
		return (0);
	if (!meta->ce_txtr || meta->ce_txtr->c[0] == '\0')
		return (0);
	if (!meta->fl_txtr || meta->fl_txtr->c[0] == '\0')
		return (0);
	return (1);
}

int	parse_dir(t_meta *meta, char *ln, bool *texture_flg)
{
	if (ln[0] == '\n')
		return (0);
	if (check_txtr_input(ln, meta->txtrs, meta))
		return (print_error(INCORRECT_COORDS));
	if (check_full_txtrs(meta))
		*texture_flg = true;
	return (0);
}
