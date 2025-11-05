/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:25:49 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/05 21:12:54 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	altitudes_and_colors(t_data *fdf, char **line, int i)
{
	int		j;
	char	*aux;

	j = 0;
	while (j < fdf->cols)
	{
		fdf->z[i][j] = ft_atoi(line[j]);
		aux = ft_strchr(line[j], ',');
		if (aux)
			fdf->pt[i][j].col = ft_atoi_hex(aux + 3);
		else
			fdf->pt[i][j].col = COLOR;
		free(line[j]);
		j ++;
	}
	free(line);
}

static void	calculate_altitudes(t_data *fdf)
{
	char	**line;
	t_list	*lst;
	int		i;

	i = 0;
	lst = fdf->fl;
	while (lst)
	{
		line = ft_split(lst->content, ' ');
		fdf->z[i] = ft_calloc(sizeof(int), fdf->cols);
		if (!fdf->z[i])
			ft_error(fdf, "Memory allocation failed\0", 1);
		fdf->pt[i] = ft_calloc(sizeof(t_point), fdf->cols);
		if (!fdf->pt[i])
			ft_error(fdf, "Memory allocation failed\0", 1);
		altitudes_and_colors(fdf, line, i);
		i ++;
		lst = lst->next;
	}
}

static void	check_size(t_data *fdf)
{
	t_list	*lst;
	size_t	len;

	lst = fdf->fl;
	len = count_words(lst->content, ' ');
	if (len == 0)
	{
		ft_cleanup(fdf);
		exit(0);
	}
	lst = lst->next;
	while (lst)
	{
		if (len != count_words(lst->content, ' '))
			ft_error(fdf, "Incorrect map size.\0", 0);
		lst = lst->next;
	}
	fdf->cols = (int)len;
}

static void	file_2_lst(t_data *fdf, int fd)
{
	t_list	*new;
	char	*line;
	char	*aux;

	line = get_next_line(fd);
	while (line)
	{
		aux = ft_strchr(line, '\n');
		while (aux)
		{
			*aux = ' ';
			aux = ft_strchr(line, '\n');
		}
		new = ft_lstnew(line);
		if (!new)
			ft_error(fdf, "Memory allocation failed\0", 1);
		ft_lstadd_back(&fdf->fl, new);
		line = get_next_line(fd);
	}
}

void	parse_file(t_data *fdf)
{
	int	fd;

	fd = open(fdf->filename, O_RDONLY);
	if (fd < 0)
		ft_error(fdf, "Open failed\0", 1);
	file_2_lst(fdf, fd);
	close(fd);
	fdf->rows = ft_lstsize(fdf->fl);
	if (!fdf->rows)
		exit(0);
	fdf->z = ft_calloc(sizeof(int *), fdf->rows);
	if (!fdf->z)
		ft_error(fdf, "Memory allocation failed\0", 1);
	fdf->pt = ft_calloc(sizeof(t_point), fdf->rows);
	if (!fdf->pt)
		ft_error(fdf, "Memory allocation failed\0", 1);
	check_size(fdf);
	calculate_altitudes(fdf);
}
