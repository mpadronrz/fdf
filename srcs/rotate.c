/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:36:29 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/05 11:55:51 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate_z(t_data *fdf, int s)
{
	float	x;
	float	y;
	int		i;
	int		j;

	i = 0;
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->cols)
		{
			x = fdf->pt[i][j].rx;
			y = fdf->pt[i][j].ry;
			fdf->pt[i][j].rx = x * cos(s * PI / 12) - y * sin(s * PI / 12);
			fdf->pt[i][j].ry = x * sin(s * PI / 12) + y * cos(s * PI / 12);
			j ++;
		}
		i ++;
	}
}

void	rotate(t_data *fdf, int kc)
{
	if (kc == KA || kc == KD)
		rotate_z(fdf, 2 * (kc == KA) - 1);
	if (fdf->view)
	{
		if (kc == KW && fdf->angle < 45)
			fdf->angle += 5;
		if (kc == KS && fdf->angle > -45)
			fdf->angle -= 5;
		paralel(fdf);
	}
	if (!fdf->view)
	{
		if (kc == KW && fdf->angle < 30)
			fdf->angle += 5;
		if (kc == KS && fdf->angle > -15)
			fdf->angle -= 5;
		isometric(fdf);
	}
}
