/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:21:20 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 21:58:09 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static bool	return_err(char *ln)
{
	print_error(INCORRECT_COLOR);
	free(ln);
	return (true);
}

bool	check_color(char *ln)
{
	int	i;

	i = 0;
	if (!ln || ft_strlen(ln) == 0)
		return (return_err(ln));
	while (ln[i] != '\0')
	{
		if (!ft_isdigit(ln[i]))
			return (return_err(ln));
		i++;
	}
	if (ft_atoi(ln) < 0 || ft_atoi(ln) > 255)
		return (return_err(ln));
	free(ln);
	return (false);
}
