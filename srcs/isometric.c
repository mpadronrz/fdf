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
            fdf->pt[i][j].px = (int)(960 + fdf->zoom * (fdf->pt[i][j].x - fdf->mid.x));
            fdf->pt[i][j].py = (int)(540 - fdf->zoom * (fdf->pt[i][j].y - fdf->mid.y));
            j ++;
        }
        i ++;
    }
    draw_board(fdf);
    //mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

void    isometric(t_data *fdf)
{
    int i;
    int j;

    i = 0;
    fdf->view = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].x = (j - i) * sqrt(3.0) / 2;
            fdf->pt[i][j].y = fdf->z[i][j] - (i + j) / 2.0;
            j ++;
        }
        i ++;
    }
    fdf->mid.x = (fdf->cols - fdf->rows) * sqrt(3.0) / 4;
    fdf->mid.y = - (fdf->cols + fdf->rows - 2) / 4.0;
    fdf->zoom = 4 * 120 / ((fdf->cols + fdf->rows - 2) * sqrt(3.0));
    if (fdf->zoom > -270 / fdf->mid.y)
        fdf->zoom = -65 / fdf->mid.y;
    calculate_pixels(fdf);
}

void    set_height(t_data *fdf, int n)
{
    float new_height;
    int i;
    int j;

    if (-1 < fdf->height && fdf->height < 1)
        new_height = fdf->height + 0.1 * n;
    else if (-5.1 < fdf->height && fdf->height < 5)
        new_height = fdf->height + 0.5 * n;
    else
        new_height = fdf->height + n;
    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].y += fdf->z[i][j] * (new_height - fdf->height);
            j ++;
        }
        i ++;
    }
    fdf->height = new_height;
    calculate_pixels(fdf);
}