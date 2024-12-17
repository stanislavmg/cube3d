/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:29:34 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:29:35 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

void	update_direction(t_player *p)
{
	p->dir.val.x = p->location.x + p->dir.norm.x * p->dir.len;
	p->dir.val.y = p->location.y + p->dir.norm.y * p->dir.len;
}
