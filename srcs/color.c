/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:14:57 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/03 11:24:21 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_pixel(t_data *fdf, int x, int y, int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16 & 0xFF) * (fdf->r != 0);
	g = (color >> 8 & 0xFF) * (fdf->g != 0);
	b = (color & 0xFF) * (fdf->b != 0);
	if (fdf->r == 1)
		r /= 2;
	if (fdf->g == 1)
		g /= 2;
	if (fdf->b == 1)
		b /= 2;
	color = r << 16 | g << 8 | b;
	ft_pixel(fdf, x, y, color);
}

void	change_color(t_data *fdf, int kc)
{
	if (kc == KR)
		fdf->r = (2 + fdf->r) % 3;
	else if (kc == KG)
		fdf->g = (2 + fdf->g) % 3;
	else if (kc == KB)
		fdf->b = (2 + fdf->b) % 3;
	draw_board(fdf);
}
