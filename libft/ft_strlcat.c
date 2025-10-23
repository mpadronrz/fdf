/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:53:41 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 11:53:41 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	pos;

	len_src = 0;
	len_dest = 0;
	pos = 0;
	while (src[len_src] != '\0')
		len_src ++;
	while (dest[len_dest] != '\0' && len_dest < size)
		len_dest ++;
	if (len_dest == size)
		return (size + len_src);
	while (len_dest + pos + 1 < size && src[pos] != '\0')
	{
		dest[len_dest + pos] = src[pos];
		pos ++;
	}
	dest[len_dest + pos] = '\0';
	return (len_src + len_dest);
}
