/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:31 by defimova          #+#    #+#             */
/*   Updated: 2024/11/07 17:19:19 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static int	check_texture_ext(char *txtr)
{
	int	len;

	len = ft_strlen(txtr);
	if (len < 5 || ft_strncmp((txtr + len - 4), ".xpm", 4))
	{
		print_error(BAD_TXTR_EXT);
		return (1);
	}
	return (0);
}

static int	free_rgb(char **rgb)
{
	free_arr((void **)rgb, free);
	return (1);
}

static int	parse_color(t_color *txtr, char *ln)
{
	char	**rgb;
	int		i;
	int		j;
	char	*tmp;

	if (txtr && txtr->c[0] != '\0')
		return (print_error(INCORRECT_COORDS));
	rgb = ft_split_ntrim(ln, ',');
	txtr->c[3] = 0;
	i = 0;
	j = 2;
	while (i != 3)
	{
		if (check_color(ft_strtrim(rgb[i], "\n")))
			return (free_rgb(rgb));
		tmp = ft_strtrim(rgb[i], "\n");
		txtr->c[j] = ft_atoi(tmp);
		free(tmp);
		j--;
		i++;
	}
	free_arr((void **)rgb, free);
	return (0);
}

static int	parse_tfile(char **txtr, char *ln)
{
	int	fd;

	if (*txtr && *txtr[0] != '\0')
		return (print_error(INCORRECT_COORDS));
	*txtr = ft_strtrim(ln, "\n");
	if (check_texture_ext(*txtr))
		return (1);
	fd = open(*txtr, O_RDONLY);
	if (fd == -1)
	{
		print_error(NO_FILE);
		return (1);
	}
	return (0);
}

int	fill_wall(char **t_arr, t_meta *m)
{
	if (!strcmp(t_arr[0], "NO") && parse_tfile(&(m->no_txtr), t_arr[1]))
		return (1);
	else if (!strcmp(t_arr[0], "SO") && parse_tfile(&(m->so_txtr), t_arr[1]))
		return (1);
	else if (!strcmp(t_arr[0], "WE") && parse_tfile(&(m->we_txtr), t_arr[1]))
		return (1);
	else if (!strcmp(t_arr[0], "EA") && parse_tfile(&(m->ea_txtr), t_arr[1]))
		return (1);
	else if (!strcmp(t_arr[0], "F") && parse_color(m->fl_txtr, t_arr[1]))
		return (1);
	else if (!strcmp(t_arr[0], "C") && parse_color(m->ce_txtr, t_arr[1]))
		return (1);
	return (0);
}
