/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:22:10 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:22:11 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	*safe_malloc(size_t str)
{
	void	*result;

	result = malloc(str);
	if (result == NULL)
		print_error("Error with the malloc\n");
	ft_bzero(result, str);
	return (result);
}
