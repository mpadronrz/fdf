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
    float   mid_x;
    float   mid_y;
    float   scale;

    mid_x = (fdf->cols - fdf->rows) * sqrt(3.0) / 4;
    mid_y = - (fdf->cols + fdf->rows - 2) / 4.0;
    scale = 4 * 120 / ((fdf->cols + fdf->rows - 2) * sqrt(3.0));
    if (scale > -270 / mid_y)
        scale = -65 / mid_y;
    i = 0;
    while (i < fdf->rows)
    {
        j = 0;
        while (j < fdf->cols)
        {
            fdf->pt[i][j].px = (int)(960 + scale * (fdf->pt[i][j].x - mid_x));
            fdf->pt[i][j].py = (int)(540 - scale * (fdf->pt[i][j].y - mid_y));
            j ++;
        }
        i ++;
    }
}

void    isometric(t_data *fdf)
{
    int i;
    int j;

    i = 0;
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
    calculate_pixels(fdf);
}