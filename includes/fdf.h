/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:24:25 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/08 21:18:53 by mapadron         ###   ########.fr       */
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

# define COLOR 0xFFFFFF
# define WIDTH 1920
# define HEIGHT 1080

# define KESC 65307
# define KUP 65362
# define KDOWN 65364
# define KRIGHT 65363
# define KLEFT 65361
# define KRE 65434
# define KAV 65435
# define KPLUS 43
# define KPLUS2 65451
# define KMINUS 45
# define KMINUS2 65453
# define KA 97
# define KB 98
# define KD 100
# define KG 103
# define KI 105
# define KM 109
# define KN 110
# define KP 112
# define KR 114
# define KS 115
# define KW 119
# define KX 120
# define KZ 122
# define PI 3.14159265

typedef struct s_color
{
	int	col;
	int	r;
	int	g;
	int	b;
	int	dr;
	int	dg;
	int	db;
}	t_color;

typedef struct s_point
{
	float	rx;
	float	ry;
	float	rz;
	float	x;
	float	y;
	int		px;
	int		py;
	int		col;

}	t_point;

typedef struct s_data
{
	t_point		**pt;
	int			**z;
	char		*filename;
	t_list		*fl;
	int			rows;
	int			cols;
	float		height;
	int			zoom;
	int			r;
	int			g;
	int			b;
	int			view;
	int			angle;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}	t_data;

//clean.c
void	ft_cleanup(t_data *fdf);
void	ft_error(t_data *fdf, char *mes, int sys_error);

//color.c
void	change_color(t_data *fdf, int kc);
void	color_pixel(t_data *fdf, int x, int y, int color);

//draw_board.c
void	calculate_pixels(t_data *fdf);
void	draw_board(t_data *fdf);

//draw_line.c
void	draw_line(t_data *fdf, t_point s, t_point e);

//draw.c
void	draw(t_data *fdf);
void	ft_pixel(t_data *data, int x, int y, int color);

//height.c
void	set_height(t_data *fdf, int n);

//isometric.c
void	isometric(t_data *fdf);
void	begin_isometric(t_data *fdf);

//math.c
float	ft_cos(float x);
float	ft_sin(float x);
int		ft_abs(int n);

//paralel.c
void	paralel(t_data *fdf);
void	begin_paralel(t_data *fdf);

//parse_file.c
void	parse_file(t_data *fdf);

//rotate.c
void	rotate(t_data *fdf, int kc);

//translate.c
void	translate(t_data *fdf, int kc);

//zoom.c
void	zoom(t_data *fdf, int t);

#endif
