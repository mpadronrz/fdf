/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:15:07 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/03 11:26:57 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calculate_pixels(t_data *fdf)
{
	int	i;
	int	j;

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

void	draw_board(t_data *fdf)
{
	int	i;
	int	j;

	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
	if (!fdf->img)
		ft_error(fdf, "Failed to create new image\0", 1);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->line_length, &fdf->endian);
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
