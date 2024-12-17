/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:28:50 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:28:51 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static t_point	get_mov_dir(t_player *p, int keysym);
static t_point	get_new_pos(t_player *p, t_point mov_dir, double delta);
static bool		check_new_pos(char **map, t_point new_pos, t_point dir);

void	move(int keysym, t_data *g, double delta)
{
	t_player	*player;
	t_point		mov_dir;
	t_point		new_pos;

	player = &g->player;
	mov_dir = get_mov_dir(player, keysym);
	new_pos = get_new_pos(player, mov_dir, delta);
	if (check_new_pos(g->m_data->map, new_pos, mov_dir))
	{
		player->location = new_pos;
		player->loc_x = new_pos.x;
		player->loc_y = new_pos.y;
		update_direction(player);
		set_fov(&player->dir, &player->fov, WIN_WIDTH, 5);
	}
}

static t_point	get_mov_dir(t_player *p, int keysym)
{
	t_point	mov_dir;

	ft_memset(&mov_dir, 0, sizeof(t_point));
	if (keysym == KEY_W)
	{
		mov_dir.x = p->dir.norm.x;
		mov_dir.y = p->dir.norm.y;
	}
	else if (keysym == KEY_D)
	{
		mov_dir.x = p->dir.norm.y;
		mov_dir.y = p->dir.norm.x * -1;
	}
	else if (keysym == KEY_S)
	{
		mov_dir.x = -p->dir.norm.x;
		mov_dir.y = -p->dir.norm.y;
	}
	else if (keysym == KEY_A)
	{
		mov_dir.x = p->dir.norm.y * -1;
		mov_dir.y = p->dir.norm.x;
	}
	return (mov_dir);
}

static t_point	get_new_pos(t_player *p, t_point mov_dir, double delta)
{
	t_point	new_pos;
	double	factor;

	factor = P_MOVE_SPEED * delta;
	ft_memset(&new_pos, 0, sizeof(t_point));
	new_pos.x = p->location.x + mov_dir.x * factor;
	new_pos.y = p->location.y + mov_dir.y * factor;
	return (new_pos);
}

static bool	check_new_pos(char **map, t_point new_pos, t_point dir)
{
	double	new_x;
	double	new_y;

	new_x = new_pos.x;
	new_y = new_pos.y;
	if (dir.x > 0)
		new_x += 0.1;
	else if (dir.x < 0)
		new_x -= 0.1;
	if (dir.y > 0)
		new_y += 0.1;
	else if (dir.y < 0)
		new_y -= 0.1;
	return (map[(int)fabs(new_y)][(int)fabs(new_x)] != '1');
}
