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

static int	close_window(t_data *fdf)
{
	ft_cleanup(fdf);
	exit(0);
	return (0);
}

void	ft_pixel(t_data *data, int x, int y, int color)
{
	int	i;

	if (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT)
	{
		i = (y * data->line_length + x * (data->bpp / 8));
		if (data->endian)
		{
			data->addr[i] = 0xFF;
			data->addr[++i] = color >> 16 & 0xFF;
			data->addr[++i] = color >> 8 & 0xFF;
			data->addr[++i] = color & 0xFF;
		}
		else
		{
			data->addr[i] = color & 0xFF;
			data->addr[++i] = color >> 8 & 0xFF;
			data->addr[++i] = color >> 16 & 0xFF;
			data->addr[++i] = 0xFF;
		}
	}
}

static int	key_hook(int kc, t_data *fdf)
{
	if (kc == KESC)
		close_window(fdf);
	if (kc == KM || kc == KN)
		set_height(fdf, 2 * (kc == KM) - 1);
	if (kc == KI)
		begin_isometric(fdf);
	if (kc == KP)
		begin_paralel(fdf);
	if (kc == KPLUS || kc == KPLUS2 || kc == KMINUS || kc == KMINUS2)
		zoom(fdf, (kc % 4 == 3));
	if (kc == KUP || kc == KDOWN || kc == KRIGHT
		|| kc == KLEFT || kc == KX || kc == KZ)
		translate(fdf, kc);
	if (kc == KA || kc == KD || kc == KW || kc == KS)
		rotate(fdf, kc);
	if (kc == KR || kc == KG || kc == KB)
		change_color(fdf, kc);
	return (0);
}

void	draw(t_data *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_error(fdf, "mlx_init failed\0", 1);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	if (!fdf->win)
		ft_error(fdf, "Failed to create new window\0", 1);
	begin_isometric(fdf);
	mlx_hook(fdf->win, 17, 0L, close_window, fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
}
