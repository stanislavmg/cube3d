#ifndef TYPES_H
#define TYPES_H

#define WIN_WIDTH 600
#define WIN_HEIGHT 800 

typedef struct	s_pos
{
	double	x;
	double	y;
} t_pos;

typedef struct	s_img
{
	void		*data;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_player
{
	t_pos	pos;
}	t_player;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

#endif