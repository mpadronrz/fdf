/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:53:41 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 11:53:41 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*str_dest;
	const unsigned char	*str_src;
	int					dif;
	size_t				i;
	size_t				counter;

	str_dest = (unsigned char *)dest;
	str_src = (const unsigned char *)src;
	if (str_dest == str_src)
		return (dest);
	dif = (2 * (str_dest < str_src) - 1);
	i = (n - 1) * (str_dest > str_src);
	counter = 0;
	while (counter < n)
	{
		str_dest[i] = str_src[i];
		i += dif;
		counter ++;
	}
	return (dest);
}
