/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:22:00 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/03 11:37:22 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(t_data *fdf, int t)
{
	if (fdf->zoom < 1000 && t)
	{
		if (fdf->zoom < 10)
			fdf->zoom ++;
		else
			fdf->zoom *= 1.2;
		calculate_pixels(fdf);
	}
	else if (fdf->zoom > 1 && !t)
	{
		fdf->zoom /= 1.2;
		calculate_pixels(fdf);
	}
}
