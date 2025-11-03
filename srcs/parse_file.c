/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:25:49 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/03 19:27:44 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	altitudes_and_colors(t_data *fdf, char **line, int i)
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
}

void	calculate_altitudes(t_data *fdf)
{
	char	**line;
	t_list	*lst;
	int		i;

	i = 0;
	lst = fdf->fl;
	line = ft_split(lst->content, ' ');
	while (line[fdf->cols])
		fdf->cols ++;
	while (i < fdf->rows)
	{
		fdf->z[i] = ft_calloc(sizeof(int), fdf->cols);
		if (!fdf->z[i])
			ft_error(fdf, "Memory allocation failed\0", 1);
		fdf->pt[i] = ft_calloc(sizeof(t_point), fdf->cols);
		if (!fdf->pt[i])
			ft_error(fdf, "Memory allocation failed\0", 1);
		altitudes_and_colors(fdf, line, i);
		free(line);
		i ++;
		lst = lst->next;
		if (!lst)
			break ;
		line = ft_split(lst->content, ' ');
	}
}

void	file_2_lst(t_data *fdf, int fd)
{
	t_list	*new;
	char	*line;
	char	*aux;

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, "\n\0", 2))
			free(line);
		else
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
}

void	check_filename(t_data *fdf)
{
	size_t	len;

	len = ft_strlen(fdf->filename);
	if (len < 4)
		ft_error(fdf, "Filename must end in .fdf\0", 0);
	if (ft_strncmp(fdf->filename + len - 4, ".fdf", 5))
		ft_error(fdf, "Filename must end in .fdf\0", 0);
}

void	parse_file(t_data *fdf)
{
	int	fd;

	check_filename(fdf);
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
	calculate_altitudes(fdf);
}
