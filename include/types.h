#ifndef TYPES_H
# define TYPES_H

# define WIN_WIDTH 1440
# define WIN_HEIGHT 900
# define mapWidth 24
# define mapHeight 24

/*** colors ***/
# define GRAY 0x808080
# define RED 0xFF0000

/*** keycodes ***/
# define KEY_ESC	53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ARROR_LEFT 123
# define KEY_ARROR_RIGHT 124

/*** player ***/
# define P_ANGLE_DEFAULT 90
# define P_ROTATE_SPEED 0.05
# define P_MOUSE_SENSITIVITY 0.008
# define P_MOVE_SPEED 5
# define FOV 1.0472
# define PI 3.1415926
# define RAY_SPEED 0.05

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