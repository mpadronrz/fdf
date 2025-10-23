/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:53:40 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 11:53:40 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len ++;
	while (n != 0)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;
	int		is_neg;

	len = int_len(n);
	nbr = ft_calloc(sizeof(char), len + 1);
	if (!nbr)
		return (NULL);
	is_neg = (n < 0);
	if (is_neg)
	{
		nbr[0] = '-';
		len --;
		nbr[len] = '0' - (n % 10);
		n /= -10;
	}
	while (len > is_neg)
	{
		len --;
		nbr[len] = '0' + (n % 10);
		n /= 10;
	}
	return (nbr);
}
