/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:                                          #+#    #+#             */
/*   Updated:                                         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t sizedest)
{
	size_t	i;

	i = 0;
	startdest = strlen(dest);
	while (dst[startdest + i] != '\0')
	{
		dst[startdest + i] = src[i];
		i++;
	}
	dest[startdest + i] = '\0';
	return (startdest + i + 1);
}
