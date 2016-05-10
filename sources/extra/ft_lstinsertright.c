/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsertright.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:51:40 by amulin            #+#    #+#             */
/*   Updated: 2016/05/10 15:51:51 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

/*
** This function inserts 'elem' right after the element pointed to by 'pos'.
** To insert an element at the head of the list, use ft_lstappend() instead.
*/

t_list		*ft_lstinsertright(t_list *elem, t_list *pos)
{
	if (!elem || !pos)
		return (NULL);
	if (pos->next)
	{
		pos->next->prev = elem;
		elem->next = pos->next;
	}
	else
		elem->next = NULL;
	elem->prev = pos;
	pos->next = elem;
	return (elem);
}
