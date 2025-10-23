/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:53:41 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 11:53:41 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_array(char **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i ++;
	}
	free(array);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	int		new_word;
	size_t	words;

	new_word = 1;
	words = 0;
	while (*s)
	{
		if (new_word && *s != c)
			words ++;
		new_word = (*s == c);
		s ++;
	}
	return (words);
}

static size_t	len_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len ++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	len;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (! array)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s ++;
		len = len_word(s, c);
		array[i] = malloc((len + 1) * sizeof(char));
		if (! array[i])
			return (free_array(array, i));
		ft_strlcpy(array[i], s, len + 1);
		s += len;
	}
	array[i] = NULL;
	return (array);
}
