/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:24:25 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/19 17:34:47 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define COLOR 0x00FFFFFF

typedef struct s_point
{
	float	x;
	float	y;
	int		px;
	int		py;
	int	col;

}	t_point;


typedef struct s_data
{
	t_point		**pt;
	int			**z;
	char		*filename;
	t_list		*fl;
	int			rows;
	int			cols;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}	t_data;

void    ft_error(t_data *fdf, char *mes, int sys_error);
void	parse_file(t_data *fdf);
void    draw(t_data *fdf);
void    isometric(t_data *fdf);
void    draw_board(t_data *fdf);
void	ft_pixel(t_data *data, int x, int y, int color);

#endif
