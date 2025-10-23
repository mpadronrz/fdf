/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:20:29 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 20:20:32 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len ++;
	return (len);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0' && i + 1 < size)
	{
		dest[i] = src[i];
		i ++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (i);
}

void	*gnl_calloc(int nmemb, int size)
{
	char	*mem;
	int		i;

	i = 0;
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	while (i < nmemb * size)
	{
		mem[i] = '\0';
		i ++;
	}
	return (mem);
}

int	gnl_charpos(char *str, char c)
{
	int	pos;

	pos = 0;
	if (!str)
		return (-1);
	while (str[pos])
	{
		if (str[pos] == c)
			return (pos + 1);
		pos ++;
	}
	return (-1);
}

int	gnl_stradd(char **dest, char *src, int len_src)
{
	char	*aux;
	int		len_dest;

	len_dest = gnl_strlen(*dest);
	aux = NULL;
	if (*dest)
		aux = *dest;
	*dest = malloc((len_src + len_dest + 1) * sizeof(char));
	if (!*dest)
	{
		if (aux)
			free(aux);
		return (1);
	}
	gnl_strlcpy(*dest, aux, len_dest + 1);
	free(aux);
	gnl_strlcpy(*dest + len_dest, src, len_src + 1);
	return (0);
}
