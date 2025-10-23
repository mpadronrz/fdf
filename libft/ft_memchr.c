/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:53:40 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 11:53:40 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;
	unsigned char		a;

	a = (unsigned char)c;
	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == a)
			return ((void *)&str[i]);
		i ++;
	}
	return (NULL);
}
