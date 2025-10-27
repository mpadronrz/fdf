/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:55:09 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/19 12:55:09 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

/*void    draw_line(t_data *fdf, t_point s, t_point e)
{
    int t;
    int range;
    int col;
    int x;
    int y;

    range = ft_abs(s.px - e.px) + ft_abs(s.py - e.py);
    t = 0;
    while (t <= range)
    {
        col = (t * e.col + (range - t) * s.col) / range;
        x = (t * e.px + (range - t) * s.px) / range;
        y = (t * e.py + (range - t) * s.py) / range;
        ft_pixel(fdf, x, y, col);
        t ++;
    }
}*/

void    init_color(t_color *color, t_point s, t_point e)
{
    color->col = s.col;
    color->dr = (e.col >> 16 & 0xFF) - (s.col >> 16 & 0xFF);
    color->dg = (e.col >> 8 & 0xFF) - (s.col >> 8 & 0xFF);
    color->db = (e.col & 0xFF) - (s.col & 0xFF);
    color->r = 0;
    color->g = 0;
    color->b = 0;
}

void    choose_color(t_color *color, int steps)
{
    int r;
    int g;
    int b;

    color->r += color->dr;
    color->g += color->dg;
    color->b += color->db;
    r = (color->col >> 16 & 0xFF) + color->r / steps;
    g = (color->col >> 8 & 0xFF) + color->g / steps;
    b = (color->col & 0xFF) + color->b / steps;
    color->col = (r << 16) | (g << 8) | b;
}

int choose_dir(t_point *s, t_point d, t_point n, int er)
{
    int er2;

    er2 = 2 * er;
    if (er2 > -d.py)
    {
        er -= d.py;
        s->px += n.px;
    }
    if (er2 < d.px)
    {
        er += d.px;
        s->py += n.py;
    }
    return (er);
}

void    draw_line(t_data *fdf, t_point s, t_point e)
{
    t_point d;
    t_point n;
    int er;
    t_color color;
    int steps;

    d.px = ft_abs(e.px - s.px);
    d.py = ft_abs(e.py - s.py);
    n.px = 2 * (e.px >= s.px) - 1;
    n.py = 2 * (e.py >= s.py) - 1;
    er = d.px - d.py;
    steps = (d.px > d.py) * (d.px - d.py) + d.py;
    init_color(&color, s, e);
    while(s.px != e.px || s.py != e.py)
    {
        choose_color(&color, steps);
        ft_pixel(fdf, s.px, s.py, color.col);
        er = choose_dir(&s, d, n, er);
    }
    ft_pixel(fdf, e.px, e.py, e.col);
}

void    draw_board(t_data *fdf)
{
    int i;
    int j;

    if (fdf->img)
        mlx_destroy_image(fdf->mlx, fdf->img);
    fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_length, &fdf->endian);
    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            if (i > 0)
                draw_line(fdf, fdf->pt[i - 1][j], fdf->pt[i][j]);
            if (j > 0)
                draw_line(fdf, fdf->pt[i][j - 1], fdf->pt[i][j]);
            j ++;
        }
        i ++;
    }
    mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}