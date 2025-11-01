/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_proj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:51:32 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/18 23:51:32 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    calculate_pixels(t_data *fdf)
{
    int i;
    int j;

    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].px = (int)(960 + fdf->zoom * (fdf->pt[i][j].x));
            fdf->pt[i][j].py = (int)(540 - fdf->zoom * (fdf->pt[i][j].y));
            j ++;
        }
        i ++;
    }
    draw_board(fdf);
}

static float   get_eff(float x)
{
    return (-x * x / 900 + x / 20 + 1);
}

void    isometric(t_data *fdf)
{
    int i;
    int j;
    float   eff;
    float   c;
    float   s;

    i = 0;
    fdf->view = 0;
    eff = get_eff(fdf->angle);
    c = ft_cos(-30 + fdf->angle);
    s = ft_sin(-30 + fdf->angle);
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].x = (fdf->pt[i][j].ry - fdf->pt[i][j].rx) * c;
            fdf->pt[i][j].y = fdf->pt[i][j].rz * eff + (fdf->pt[i][j].ry + fdf->pt[i][j].rx) * s;
            j ++;
        }
        i ++;
    }
    calculate_pixels(fdf);
}

void    set_height(t_data *fdf, int n)
{
    int i;
    int j;

    if (-1 <= fdf->height + 0.1 * n && fdf->height + 0.1 * n <= 1)
        fdf->height += 0.1 * n;
    else if (-5 <= fdf->height + 0.5 * n && fdf->height + 0.5 * n <= 5)
        fdf->height += 0.5 * n;
    else
        fdf->height += n;
    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].rz = fdf->z[i][j] * fdf->height;
            j ++;
        }
        i ++;
    }
    if (fdf->view)
        paralel(fdf);
    else
        isometric(fdf);
}

void    begin_isometric(t_data *fdf)
{
    int i;
    int j;

    i = 0;
    fdf->view = 0;
    fdf->height = 1;
    fdf->angle = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].rx = i - fdf->rows / 2.0;
            fdf->pt[i][j].ry = j - fdf->cols / 2.0;
            fdf->pt[i][j].rz = fdf->z[i][j];
            j ++;
        }
        i ++;
    }
    fdf->zoom = 4 * 120 / ((fdf->cols + fdf->rows - 2) * sqrt(3.0));
    isometric(fdf);
}