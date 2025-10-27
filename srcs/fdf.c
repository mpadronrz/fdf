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

void    ft_endl(void *ptr)
{
    char    *str;

    str = (char*)ptr;
    write(1, str, ft_strlen(str));
}

void    fdf_init(t_data *fdf)
{
    fdf->pt = NULL;
	fdf->z = NULL;
	fdf->filename = NULL;
	fdf->fl = NULL;
    fdf->height = 1.0;
    fdf->rows = 0;
    fdf->cols = 0;
	fdf->mlx = NULL;
	fdf->win = NULL;
    fdf->img = NULL;
	fdf->addr = NULL;
	fdf->bpp = 0;
	fdf->line_length = 0;
	fdf->endian = 0;
}

int main(int argc, char **argv)
{
    t_data  fdf;

    if (argc != 2)
        ft_error(&fdf, "Must pass one and only one file as parameter.", 0);
    fdf_init(&fdf);
    fdf.filename = argv[1];
    parse_file(&fdf);
    draw(&fdf);
    return (0);
}
