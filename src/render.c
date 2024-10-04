#include "limits.h"
#include "init.h"

void draw_vertical_line(double offset, t_text *t, t_img *img, double dist, int x);

double	get_offset(t_grid *g, t_pos p)
{
	int	i;
	t_line	**h;
	t_line	**v;
	double	offset;

	i = 0;
	h = g->hor;
	v = g->vert;
	offset = 0;
	while (h[i])
	{
		//(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)
		if ((int)((p.x - h[i]->start->x) / (h[i]->end->x - h[i]->start->x)) ==
			(int)((p.y - h[i]->start->y) / (h[i]->end->y - h[i]->start->y)))
			offset = (int)p.x % 64;
		i++;
	}
	i = 0;
	while (v[i])
	{
		if ((p.x - v[i]->start->x) / (v[i]->end->x - v[i]->start->x) ==
			(p.y - v[i]->start->y) / (v[i]->end->y - v[i]->start->y))
			offset = (int)p.y % 64;
		i++;
	}
	printf("offset = %f\n", offset);
	return (offset);
}

void	draw_frame(t_data *g)
{
	int 	x;
	t_ray	r;
	double	dist;

	if (!g)
		return ;
	x = -1;
	while (++x < WIN_WIDTH)
	{
		r.dir = g->p.angle + FOV / 2 - x * FOV / WIN_WIDTH;
		r.pos.x = sin(r.dir);
		r.pos.y = cos(r.dir);
		dist = cast_ray(&r.pos, &g->p.pos);
		double	offset = get_offset(g->map_grid, r.pos);
		draw_vertical_line(offset, &g->wall[0], &g->main_img, dist, x);
	}
	//printf("wall height = %d\n width = %d\n", g->wall->height, g->wall->width);
	mlx_put_image_to_window(g->win_mng.mlx, g->win_mng.win, g->main_img.data, 0, 0);
}

double	cast_ray(t_pos *r, t_pos *p)
{
	int		tx;
	int		ty;
	t_pos	t;
	int		hit;
	double	dist;
	double	deph;

	hit = 0;
	dist = 0.0;
	deph = 24;
	if (!r || !p)
		return (0.0);
	while (!hit && dist < deph)
	{
		t.x = (int)(p->x + r->x * dist);
		t.y = (int)(p->y + r->y * dist);
		tx = t.x;
		ty = t.y;
		dist += RAY_SPEED;
		if (tx < 0 || tx >= deph + p->x || ty < 0 || ty >= deph + p->y)
		{
			hit = 1;
			dist = deph;
		}
		if (worldMap[tx][ty] == '1')
			hit = 1;
	}
	r->x = t.x;
	r->y = t.y;
	return (dist);
}

void draw_vertical_line(double offset, t_text *t, t_img *img, double dist, int x)
{
    if (!img || !t || !t->img.data_addr)
        return;

    int wall = (int)(WIN_HEIGHT / 2 - WIN_HEIGHT * FOV / dist);
    int floor = WIN_HEIGHT - wall;

    double ty = 0.0;
    double ty_step = 64.0 / (double)wall; 
	//int one_txt = WIN_WIDTH / mapWidth;
    int tx = x % wall; 
	(void)offset;
    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        int color;

        if (y < wall)
            color = BLUE; 
        else if (y >= wall && y < floor)
        {
            int textureY = (int)ty;
            // if (textureY < 0) textureY = 0;
            // if (textureY >= t->height) textureY = textureY % 64; // Loop texture
            color = ((int*)(t->img.data_addr))[textureY * (64/4) + tx];
        	put_pixel(x, y, img, color);
            ty += ty_step;
        }
        else
            color = GREEN;
        put_pixel(x, y, img, color);
    }
}

void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || y < 0 || !img || color < 0)
		return ;
	offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->data_addr + offset) = color;
}
