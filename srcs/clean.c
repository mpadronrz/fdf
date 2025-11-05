/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:25:39 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/02 23:45:33 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	clean_mlx(t_data *fdf)
{
	if (fdf->mlx)
	{
		if (fdf->img)
			mlx_destroy_image(fdf->mlx, fdf->img);
		if (fdf->win)
			mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
}

void	ft_cleanup(t_data *fdf)
{
	int	i;

	clean_mlx(fdf);
	i = 0;
	while (i < fdf->rows)
	{
		free(fdf->pt[i]);
		free(fdf->z[i]);
		i ++;
	}
	ft_lstclear(&fdf->fl, free);
	free(fdf->pt);
	free(fdf->z);
}

void	ft_error(t_data *fdf, char *mes, int sys_error)
{
	ft_cleanup(fdf);
	if (sys_error)
		perror(mes);
	else
	{
		write(2, mes, ft_strlen(mes));
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
