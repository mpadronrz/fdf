/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:53:41 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 11:53:41 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	start = 0;
	while (start < len && ft_strchr(set, s1[start]))
		start ++;
	if (start == len)
	{
		str = ft_calloc(sizeof(char), 1);
		if (! str)
			return (NULL);
		return (str);
	}
	len --;
	while (ft_strchr(set, s1[len]))
		len --;
	str = ft_substr(s1, start, len + 1 - start);
	return (str);
}
