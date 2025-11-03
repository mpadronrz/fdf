/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:53:40 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/03 11:39:21 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (nbr[i] == ' ' || (9 <= nbr[i] && nbr[i] <= 13))
		i ++;
	if (nbr[i] == '-')
	{
		sign = -1;
		i ++;
	}
	else if (nbr[i] == '+')
		i ++;
	while ('0' <= nbr[i] && nbr[i] <= '9')
	{
		n = 10 * n + (nbr[i] - '0');
		i ++;
	}
	return (sign * n);
}

int	ft_atoi_hex(const char *nbr)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (('0' <= nbr[i] && nbr[i] <= '9') || ('a' <= nbr[i] && nbr[i] <= 'f')
		|| ('A' <= nbr[i] && nbr[i] <= 'F'))
	{
		if ('0' <= nbr[i] && nbr[i] <= '9')
			n = 16 * n + (nbr[i] - '0');
		else if ('a' <= nbr[i] && nbr[i] <= 'f')
			n = 16 * n + (nbr[i] - 'a' + 10);
		else if ('A' <= nbr[i] && nbr[i] <= 'F')
			n = 16 * n + (nbr[i] - 'A' + 10);
		i ++;
	}
	return (n);
}
