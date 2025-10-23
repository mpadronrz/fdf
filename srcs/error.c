/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:25:39 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/18 22:10:04 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    ft_error(t_data *fdf, char *mes, int sys_error)
{
    (void)fdf;
    //ft_cleanup(fdf);
    if (sys_error)
        perror(mes);
    else
	{
        write(2, mes, ft_strlen(mes));
		write(2, "\n", 1);
	}
    exit(EXIT_FAILURE);
}
