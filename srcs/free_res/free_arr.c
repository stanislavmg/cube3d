/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:24:30 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:24:31 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	*free_arr(void **arr, void (*free_func)(void *))
{
	void	**tmp;

	tmp = arr;
	while (*arr)
	{
		(*free_func)(*arr);
		arr++;
	}
	free(tmp);
	return (NULL);
}
