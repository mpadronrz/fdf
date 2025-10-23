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

void    draw_line(t_data *fdf, t_point s, t_point e)
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
}

void    draw_board(t_data *fdf)
{
    int i;
    int j;

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
            mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
            j ++;
        }
        i ++;
    }
}