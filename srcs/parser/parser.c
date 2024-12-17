/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:17:53 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:17:54 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"
#include <stdbool.h>

static int	ext_check(char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (file[i] != '.')
		i++;
	if (file[i + 1] != 'c' || file[i + 2] != 'u' || file[i + 3] != 'b'
		|| file[i + 4] != '\0')
	{
		print_error(INCORRECT_FILE);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(NO_FILE);
	return (fd);
}

static bool	try_parse_map(bool *map_flg, t_meta *metadata, char *ln)
{
	if (parse_map(metadata, ln, map_flg))
		return (false);
	return (true);
}

static int	parse_line(int fd, t_meta *metadata)
{
	char	*ln;
	bool	texture_flg;
	bool	map_flg;

	texture_flg = false;
	map_flg = false;
	ln = get_next_line(fd);
	while (ln && *ln)
	{
		if (!texture_flg)
		{
			if (parse_dir(metadata, ln, &texture_flg))
				return (free_ln_err(ln));
		}
		else if (!try_parse_map(&map_flg, metadata, ln))
			return (1);
		free(ln);
		ln = get_next_line(fd);
	}
	free(ln);
	return (0);
}

int	fill_map_arr(t_meta *metadata)
{
	metadata->map = ft_split(metadata->map_str, '\n');
	if (!metadata->map)
	{
		print_error(FATAL);
		return (1);
	}
	return (0);
}

int	parser(char **argv, t_meta *metadata)
{
	int	fd;

	fd = ext_check(argv[1]);
	if (fd < 0)
		return (1);
	if (parse_line(fd, metadata))
	{
		close(fd);
		return (1);
	}
	if (fill_map_arr(metadata))
		return (1);
	if (check_map(metadata, metadata->map))
		return (1);
	return (0);
}
