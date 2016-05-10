/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdetach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:49:45 by amulin            #+#    #+#             */
/*   Updated: 2016/05/10 15:51:12 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

/*
** This function detaches an element from the list without deleting it.
*/

t_list		*ft_lstdetach(t_list *elem)
{
	if (!elem)
		return (NULL);
	if (elem->prev)
		elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	elem->prev = NULL;
	elem->next = NULL;
	return (elem);
}
