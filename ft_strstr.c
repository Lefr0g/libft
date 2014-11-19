/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:42:59 by amulin            #+#    #+#             */
/*   Updated: 2014/11/19 16:38:04 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (haystack[i] == needle[j] && haystack[i] == 0)
		return ("");
	while (haystack[i] != '\0')
	{
		if (needle[j] == '\0')
			return ((char*)&haystack[i - j]);
		if (haystack[i] == needle[j])
			j++;
		i++;
		if (needle[j] == '\0')
			return ((char*)&haystack[i - j]);
	}
	return (NULL);
}
