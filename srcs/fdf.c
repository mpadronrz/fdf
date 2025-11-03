/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:35:34 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/19 00:18:04 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_init(t_data *fdf)
{
	fdf->pt = NULL;
	fdf->z = NULL;
	fdf->filename = NULL;
	fdf->fl = NULL;
	fdf->height = 1.0;
	fdf->rows = 0;
	fdf->cols = 0;
	fdf->angle = 0;
	fdf->r = 2;
	fdf->g = 2;
	fdf->b = 2;
	fdf->mlx = NULL;
	fdf->win = NULL;
	fdf->img = NULL;
	fdf->addr = NULL;
	fdf->bpp = 0;
	fdf->line_length = 0;
	fdf->endian = 0;
}

int	main(int argc, char **argv)
{
	t_data	fdf;

	fdf_init(&fdf);
	if (argc != 2)
		ft_error(&fdf, "Must pass one and only one file as parameter.", 0);
	fdf.filename = argv[1];
	parse_file(&fdf);
	draw(&fdf);
	return (0);
}
