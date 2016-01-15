/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:23:04 by amulin            #+#    #+#             */
/*   Updated: 2014/12/08 17:54:05 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*ptr;

	ptr = *alst;
	if (alst && *alst && new)
	{
		while (ptr->next)
			ptr = ptr->next;
		new->next = *alst;
		new->prev = NULL;
		*alst = new;
	}
}
