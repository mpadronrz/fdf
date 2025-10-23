/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapadron <mapadron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:53:40 by mapadron          #+#    #+#             */
/*   Updated: 2025/10/03 11:53:40 by mapadron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pos;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	pos = *lst;
	while (pos)
	{
		next = pos->next;
		ft_lstdelone(pos, del);
		pos = next;
	}
	*lst = NULL;
}
