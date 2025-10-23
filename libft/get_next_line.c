/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:20:09 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 20:20:12 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	extra_bytes(char **str, char **line, int pos)
{
	char	*aux;
	int		len;

	len = gnl_strlen(*line);
	if (pos < 0 || pos == len)
	{
		*str = NULL;
		return (0);
	}
	aux = malloc((pos + 1) * sizeof(char));
	if (!aux)
		return (1);
	gnl_strlcpy(aux, *line, pos + 1);
	*str = malloc((len - pos + 1) * sizeof(char));
	if (!*str)
	{
		free(aux);
		return (1);
	}
	gnl_strlcpy(*str, *line + pos, len - pos + 1);
	free(*line);
	*line = aux;
	return (0);
}

int	read_line(int fd, char **line, int *pos)
{
	char	*buffer;
	int		bytes;

	buffer = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (1);
	while (*pos < 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free(buffer);
			return (1);
		}
		if (gnl_stradd(line, buffer, bytes))
		{
			free(buffer);
			return (1);
		}
		*pos = gnl_charpos(*line, '\n');
	}
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;
	int			pos;

	if (fd < 0)
		return (NULL);
	line = str;
	pos = gnl_charpos(line, '\n');
	if (pos < 0 && read_line(fd, &line, &pos))
	{
		if (line)
			free(line);
		str = NULL;
		return (NULL);
	}
	if (extra_bytes(&str, &line, pos))
	{
		str = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
