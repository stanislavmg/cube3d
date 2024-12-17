/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:06:12 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 22:06:13 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define WIN_WIDTH 1400
# define WIN_HEIGHT 900

# define P_ROTATE_SPEED 2
# define P_MOVE_SPEED 15

# define FOV 0.585398
# define PI 3.1415926
# define FPS 60

# ifdef __APPLE__
#  define KEY_ESC			53
#  define KEY_W				13
#  define KEY_A				0
#  define KEY_S				1
#  define KEY_D				2
#  define KEY_ARROW_LEFT		123
#  define KEY_ARROW_RIGHT	124
#  define ON_KEYDOWN			2
#  define ON_DESTROY			17
#  define KEY_PRESS_MASK		1	
#  define DESTROY_MASK		0
#  define NO_EVENT_MASK		0
# else
#  include <X11/keysym.h>
#  include <X11/X.h>

#  define KEY_ESC			XK_Escape
#  define KEY_W				XK_w
#  define KEY_A				XK_a
#  define KEY_S				XK_s
#  define KEY_D				XK_d
#  define KEY_ARROW_LEFT		XK_Left
#  define KEY_ARROW_RIGHT	XK_Right

#  define ON_KEYDOWN			KeyPress
#  define ON_DESTROY			DestroyNotify
#  define KEY_PRESS_MASK		KeyPressMask
#  define DESTROY_MASK		StructureNotifyMask	
#  define NO_EVENT_MASK		NoEventMask
# endif

typedef struct s_img
{
	void	*data;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_text
{
	int		width;
	int		height;
	t_img	img;
}	t_text;

typedef struct s_render_info
{
	t_text	*t;
	t_img	*img;
	double	ty;
	double	tx;
	double	ty_off;
	double	ty_step;
	int		wall_height;
	int		wall_offset;
	int		floor_offset;
}	t_render_info;

#endif
