/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:36:49 by amulin            #+#    #+#             */
/*   Updated: 2014/12/08 18:40:27 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*fresh;

	if (lst != NULL && (*f) != NULL)
	{
		buf = lst;
		fresh = ft_lstnew(NULL, 0);
		fresh = (*f)(buf);
		buf = buf->next;
		while (buf->next != NULL)
		{
			ft_lstadd(&fresh, buf);
			fresh = (*f)(buf);
			buf = buf->next;
		}
	}
	return (fresh);
}
