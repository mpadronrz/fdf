/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:53:41 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 11:53:41 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(sizeof(char));
		if (! sub)
			return (NULL);
		sub[0] = 0;
		return (sub);
	}
	if (start + len > s_len)
		len = s_len - start;
	sub = malloc((len + 1) * sizeof(char));
	if (! sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
