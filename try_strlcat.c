/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:59:43 by amulin            #+#    #+#             */
/*   Updated: 2014/11/11 12:59:47 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	try_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lensrc;
	// A partir du debut de size, trouver le premier \0
	// Si pas de \0, return size
	i = 0;
	j = 0;
	lensrc = ft_strlen(src);
	while (dest[i] != '\0' && i < size)
		i++;
	if (size - i == 0)
		return (size);

	// Copier src dans dst char par char
	while (i + j <= size && j <= lensrc)
	{
		dest[i + j] = src[j];
		j++;
	}
	// Arrive au dernier char de size, entrer \0 dans dst
	dest[i + j] = '\0';
	// Renvoyer strlen(dst) + strlen(src)
	return (ft_strlen(dst) + lensrc);
}
