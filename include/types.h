#ifndef TYPES_H
# define TYPES_H

# define WIN_WIDTH 1440
# define WIN_HEIGHT 900
# define mapWidth 24
# define mapHeight 24

/*** colors ***/
# define GRAY	0x808080
# define RED	0xFF0000
# define BLUE	0x87CEEB
# define GREEN	0x228B22

/*** keycodes ***/
#ifdef __APPLE__
	# define KEY_ESC			53
	# define KEY_W				13
	# define KEY_A				0
	# define KEY_S				1
	# define KEY_D				2
	# define KEY_ARROW_LEFT		123
	# define KEY_ARROW_RIGHT	124
#else
	# include <X11/keysym.h>
	# include <X11/X.h>
	# define KEY_ESC			XK_Escape
	# define KEY_W				XK_w
	# define KEY_A				XK_a
	# define KEY_S				XK_s
	# define KEY_D				XK_d
	# define KEY_ARROW_LEFT		XK_Left
	# define KEY_ARROW_RIGHT	XK_Right
#endif


/*** player ***/
# define P_ANGLE_DEFAULT 66
# define P_ROTATE_SPEED 5
# define P_MOUSE_SENSITIVITY 0.008
# define P_MOVE_SPEED 8
# define P_START_POSITION 5.0

/*** game ***/
# define FOV 1.0472
# define PI 3.1415926
# define RAY_SPEED 0.1
# define FPS 90

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_ray
{
	t_pos	pos;
	double	dir;
}	t_ray;

typedef struct	s_img
{
	void	*data;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct	s_player
{
	t_pos	pos;
	t_img	img;
	t_mlx	*wm;
	double	dir;
	double	angle;
	double	move_speed;
	double	rotate_speed;
	double	mouse_sens;
}	t_player;

typedef struct	s_data
{
	t_mlx		*wm;
	t_player	p;
}	t_data;

#endif