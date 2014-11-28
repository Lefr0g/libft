/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 12:27:27 by amulin            #+#    #+#             */
/*   Updated: 2014/11/28 20:00:50 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	char	*buf;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	i = 0;
	buf = (char*)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (buf == NULL)
		return (NULL);
	while (i < lens1)
	{
		buf[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		buf[lens1 + i] = s2[i];
		i++;
	}

	buf[lens1 + i] = '\0';
	return (buf);
}
