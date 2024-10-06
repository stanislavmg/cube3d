#include "limits.h"
#include "init.h"
#include "tmp.h"


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
float FixAng(float a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}
void	draw_frame(t_data *g)
{
	int 	x;
	t_ray	r;
	double	dist;

	if (!g)
		return ;
	x = -1;
	r.dir = 0;
	while (++x < WIN_WIDTH)
	{
		r.dir = g->p.angle + FOV / 2 - x * FOV / WIN_WIDTH;
		float ca = g->p.angle - r.angle;
		r.pos.x = sin(r.dir);
		r.pos.y = cos(r.dir);
		dist = cast_ray(&r.pos, &g->p.pos);
		dist = dist * cos(g->p.angle - r.dir);
		(void)ca;
		double	offset = get_offset(g->map_grid, r.pos);
		draw_vertical_line(&r, offset, &g->wall[0], &g->main_img, dist, x);
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
void draw_vertical_line(t_ray *r, double offset, t_text *t, t_img *img, double dist, int x)
{
    if (!img || !t || !t->img.data_addr)
        return;
	
	int c;
    int wall = (int)(WIN_HEIGHT / 2 - WIN_HEIGHT * FOV / dist);
    int floor = WIN_HEIGHT - wall;

    double ty = 0.0;
	double tx = (int)(r->pos.y / 2.0) % 32;
	if (r->dir > 90 && r->dir < 270) { tx = 31 - tx;}
	(void)r;
    double ty_step; 
	(void)offset;
    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        if (y < wall)
            c = BLUE; 
        else if (y >= wall && y < floor)
        {
			if (y == wall)
				ty_step = 32.0 / (floor - y);
			if (All_Textures[(int)(ty) * 32 + (int)tx] == 0)
				c = 0x000000;
			else
				c = 0xFFFFFF;
        	ty += ty_step;
        }
		else
            c = GREEN;
        put_pixel(x, y, img, c);
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