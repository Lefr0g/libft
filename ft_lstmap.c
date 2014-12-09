/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:36:49 by amulin            #+#    #+#             */
/*   Updated: 2014/12/09 17:59:11 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
/*
atic void	ft_lstaddqueue(t_list **alst, t_list *new)
{
	t_list	*buf;

	if (alst != NULL && new != NULL)
	{
		buf = *alst;
		while (buf->next != NULL)
			buf = buf->next;
		buf->next = new;
		new->next = NULL;
	}
}
*/
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*fresh;
	t_list	*freshinit;
	
//	fresh = (t_list*)malloc(sizeof(t_list));
//	fresh->next = (t_list*)malloc(sizeof(t_list));
//	if (fresh == NULL || fresh->next == NULL)
//		return (NULL);
	if (lst != NULL && (*f) != NULL)
	{
		buf = lst;
		fresh = ft_lstnew(NULL, 0);
		freshinit = fresh;
		while (buf != NULL)
		{
			printf("\nConditions initiales Ok pour fonction principale\n");
			fresh = (*f)(buf);
			printf("\nbuf = %p, buf->next = %p", buf, buf->next);
			printf("\nfresh = %p, fresh->next = %p", fresh, fresh->next);
			if (buf->next != NULL)
				fresh->next = ft_lstnew(NULL, 0);
			printf("\nfresh = %p, fresh->next = %p", fresh, fresh->next);
			fresh = fresh->next;
			buf = buf->next;
		}


/*
		printf("\nConditions initiales Ok pour fonction principale\n");
		buf = lst;
		fresh = ft_lstnew(NULL, 0);
		fresh = (*f)(buf);
		printf("\nbuf = %p, buf->next = %p", buf, buf->next);
		printf("\nfresh->content_size = %zd\n", fresh->content_size);
		buf = buf->next;
		printf("\nbuf = %p", buf);
		while (buf != NULL)
		{
			printf("\nBoucle fresh->next engagee\n");
//			fresh = fresh->next;
			fresh->next = (t_list*)malloc(sizeof(t_list));
			if (fresh->next == NULL)
				return (NULL);
//			fresh->next = (t_list*)malloc(sizeof(t_list));
			ft_lstaddqueue(&(fresh->next), (*f)(buf));
//			fresh = (*f)(buf);
			buf = buf->next;
			fresh = fresh->next;
		} */
		printf("\nFin : freshinit->content_size = %zd", freshinit->content_size);
		printf("\nFin : freshinit->next->content_size = %zd\n", freshinit->next->content_size);
	}
	return (freshinit);
}
