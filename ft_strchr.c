/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:21:07 by amulin            #+#    #+#             */
/*   Updated: 2014/11/11 17:34:56 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*new;

	i = 0;
	new = (const char*)malloc(sizeof(s));
	while (s[i] != '\0')
	{
		if (s[i + 1] == c)
		{
			new = &s[i + 1];
			return ((char*)new);
		}
		i++;
	}
	return (NULL);
}
