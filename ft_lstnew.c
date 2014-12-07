/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 19:41:41 by amulin            #+#    #+#             */
/*   Updated: 2014/12/05 19:46:15 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*buf;

	buf = (t_list*)malloc(sizeof(*buf));
	if (buf == NULL)
		return (NULL);
	if (content == NULL)
	{
		buf->content = NULL;
		buf->content_size = 0;
	}
	else
	{
		ft_memcpy(buf->content, content, content_size);
		buf->content_size = content_size;
	}
	buf->next = NULL;
	return (buf);
}
