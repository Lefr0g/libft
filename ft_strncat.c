/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:                                          #+#    #+#             */
/*   Updated:                                         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	lendest;
	size_t	i;

	lendest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (dest);
}
