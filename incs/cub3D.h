/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:06:00 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 22:06:04 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef __linux__
#  define IS_LINUX 1	
# else
#  define IS_LINUX 0	
# endif

# define INCORRECT_COORDS \
	"Incorrect textures in .cub - check coords\n"
# define INCORRECT_FORMAT \
	"Incorrect .cub format - leave empty line before FLOOR texture\n"
# define INCORRECT_FILE \
	"Incorrect file type. Shall be .cub\n"
# define INCORRECT_COLOR \
	"Incorrect color input. Check is it a correct RGB format\n"
# define INCORRECT_MAP_SYMBOL \
"Incorrect symbol passed in map scratch. Valid are [0, 1, W, E, S, N, SPACE]\n"
# define MULTIPLE_PLAYERS \
	"There can not be more than 1 player in the Game, check input file!\n"

# define ZERO_PLAYERS	"There can't be zero players, check input file!\n"
# define BADMAP			"Incorrect map, shall be framed with walls!\n"
# define BAD_TXTR_EXT	"Incorrect texture extention, shall be .xpm\n"
# define LONGMAP		"Map is too big, maximum is MAXINTxMAXINT!\n"
# define FATAL			"Error: fatal\n"
# define NO_FILE		"File passed as map or texture doesn't exist\n"
# define EMPTYLINEINMAP "Empty line inside map\n"

# define RESET	"\033[0m"
# define RED	"\033[1;31m"
# define BLUE	"\033[1;34m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "draw.h"
# include "mlx.h"

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}	t_line;

typedef struct s_grid
{
	t_line	**vert;
	t_line	**hor;
}	t_grid;

typedef union u_color
{
	int		i;
	char	c[4];
}	t_color;

typedef struct s_meta
{
	char			*no_txtr;
	char			*so_txtr;
	char			*we_txtr;
	char			*ea_txtr;
	t_color			*fl_txtr;
	t_color			*ce_txtr;
	char			**map;
	char			*map_str;
	unsigned int	maplen;
	int				player_pos[3];
	char			*txtrs[7];
}	t_meta;

typedef struct s_wallhit
{
	double	distance;
	t_point	hit;
	double	offset;
	int		is_vert;
	char	orientation;
}	t_wallhit;

typedef struct s_vector
{
	t_point	norm;
	t_point	val;
	double	len;
}	t_vector;

typedef struct s_fov
{
	t_point	start;
	t_point	end;
	double	width;
	double	iter_x;
	double	iter_y;
}	t_fov;

typedef struct s_player
{
	int			loc_x;
	int			loc_y;
	t_point		location;
	t_vector	dir;
	t_fov		fov;
}	t_player;

typedef struct s_calc
{
	bool		is_vert;
	char		orients[2];
	double		len_delta;
	double		wall_face_dir;
	t_vector	ray_hit;
}	t_calc;

typedef struct s_ray
{
	double	x;
	double	y;
	double	len;
}	t_ray;

typedef struct _data
{
	t_meta		*m_data;
	t_mlx		win_mng;
	t_img		main_img;
	t_text		*wall;
	t_player	player;
	t_wallhit	*wh;
}	t_data;

void		print_grid_lines(t_grid *grid);
void		print_wallhit(t_wallhit *wallhit, int screen_width);
void		print_metadata(t_meta *meta);
void		*free_arr(void **arr, void (*free_func)(void *));
t_data		*free_data(t_data *g);
void		free_meta(t_meta *meta);
void		free_mlx(t_mlx *wm, void *main_img, void *text);
int			free_ln_err(char *ln);
void		draw_frame(const t_data *g);
void		draw_vertical_line(t_render_info *i, int x, t_meta *metadata);
int			exit_game(t_data *data);
t_data		*game_init(t_meta *metadata);
double		get_delta_time(void);
int			hooks_init(t_mlx *wm, t_data *g);
int			on_key_pressed(int keysym, t_data *g);
int			check_map(t_meta *meta, char **map);
int			fill_wall(char **t_arr, t_meta *m);
t_meta		*meta_init(char **argv);
int			parse_dir(t_meta *meta, char *ln, bool *texture_flg);
int			parse_map(t_meta *meta, char *ln, bool *map_flg);
int			parser(char **argv, t_meta *metadata);
int			flood_fill(char **map, int x, int y);
void		init_player(t_player *player, t_meta *metadata);
void		move(int keysym, t_data *g, double delta);
void		rotate(int keysym, t_player *player, double delta);
void		set_direction(t_player *player, int dir_key, int len);
void		set_fov(t_vector *dir, t_fov *fov, int screen_width,
				double fov_width);
void		update_direction( t_player *p);
double		delta_len(int index, t_point ray);
t_calc		find_wall(t_calc *calc_data, t_point loc, char **map);
t_grid		*get_grid(char **map);
int			get_line_inds(int *indexes, t_point location, t_point dir);
double		get_vectors_cos_angle(double proj_x, double proj_y, double raydir_x,
				double raydir_y);
t_vector	ray_hit_len(
				int *line_inds, int index, t_player *player, t_vector *ray);
int			raycast(t_player *player, t_wallhit *hits, int scr_width,
				char **map);
bool		check_color(char *ln);
bool		ft_isspace(const char a);
int			ft_strcmp(char *s1, char *s2);
char		**ft_split_ntrim(char const *s, char c);
int			print_error(char *mes);
void		*safe_malloc(size_t str);

#endif
