/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 00:03:02 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/19 00:18:55 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void    draw(t_data *fdf)
{
    fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_length, &fdf->endian);
    isometric(fdf);
    draw_board(fdf);
    mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
    mlx_loop(fdf->mlx);
}
