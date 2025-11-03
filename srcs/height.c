/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:15:18 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/03 11:50:02 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_height(t_data *fdf, int n)
{
	int		i;
	int		j;
	float	old_height;

	old_height = fdf->height;
	if (-1 <= fdf->height + 0.1 * n && fdf->height + 0.1 * n <= 1)
		fdf->height += 0.1 * n;
	else if (-5 <= fdf->height + 0.5 * n && fdf->height + 0.5 * n <= 5)
		fdf->height += 0.5 * n;
	else
		fdf->height += n;
	i = 0;
	while (i < fdf->rows)
	{
		j = -1;
		while (++j < fdf->cols)
			fdf->pt[i][j].rz += fdf->z[i][j] * (fdf->height - old_height);
		i ++;
	}
	if (fdf->view)
		paralel(fdf);
	else
		isometric(fdf);
}
