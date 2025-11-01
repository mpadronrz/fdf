/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_xy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:01:54 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/01 16:08:57 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    rotate_par_xy(t_data *fdf, int kc)
{
    float   x;
    float   y;
    int     s;
    int     i;
    int     j;

    s = 2 * (kc == KD) - 1;
    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            x = 2 * (fdf->z[i][j] * fdf->height - fdf->pt[i][j].y) / sqrt(2.0);
            y = fdf->pt[i][j].x + sqrt(2.0) * x / 2.0;
            fdf->pt[i][j].x = sin(s * AL) * (x + sqrt(2.0) * y / 2) + cos(s * AL) * (y - sqrt(2.0) * x / 2);
            fdf->pt[i][j].y = fdf->z[i][j] * fdf->height + sin(s * AL) * sqrt(2.0) * y / 2 - cos(s * AL) * sqrt(2.0) * x / 2;
            j ++;
        }
        i ++;
    }
}

void    rotate_iso_xy(t_data *fdf, int kc)
{
    float   x;
    float   y;
    int     s;
    int     i;
    int     j;

    s = 2 * (kc == KD) - 1;
    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            x = fdf->pt[i][j].x;
            y = fdf->z[i][j] * fdf->height - fdf->pt[i][j].y;
            fdf->pt[i][j].x = x * cos(s * AL) + sqrt(3.0) * y * sin(s * AL);
            fdf->pt[i][j].y = x * sin(s * AL) / sqrt(3.0) - y * cos(s * AL) + fdf->z[i][j] * fdf->height;
            j ++;
        }
        i ++;
    }
}

void    rotate_xy(t_data *fdf, int kc)
{
    if (fdf->view)
        rotate_par_xy(fdf, kc);
    if (!fdf->view)
        rotate_iso_xy(fdf, kc);
    calculate_pixels(fdf);
}