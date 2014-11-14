/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:40:51 by amulin            #+#    #+#             */
/*   Updated: 2014/11/14 17:37:13 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	enddst;

	i = 0;
	enddst = ft_strlen(dst);
	while (i < size - 1 || src[i] != '\0')
	{
		dst[enddst + i] = src[i];
		i++;
	}
	dst[enddst + i] = '\0';
	return (enddst + ft_strlen(src));
}
