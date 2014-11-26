/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:42:59 by amulin            #+#    #+#             */
/*   Updated: 2014/11/26 14:54:51 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			j++;
			i++;
		}
		else if (needle[j] == '\0')
			return ((char*)&haystack[i - j]);
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (haystack[i] == '\0' && needle[j] == '\0')
		return ((char*)&haystack[i - j]);
	return (NULL);
}
