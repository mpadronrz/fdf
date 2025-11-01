/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:06:57 by mapadron          #+#    #+#             */
/*   Updated: 2025/11/01 17:09:37 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float   ft_cos(float x)
{
    return (cos(x * PI / 180));
}

float   ft_sin(float x)
{
    return (sin(x * PI / 180));
}