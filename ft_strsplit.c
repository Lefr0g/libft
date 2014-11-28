/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 12:37:17 by amulin            #+#    #+#             */
/*   Updated: 2014/11/28 20:54:19 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//	utiliser strchr en boucle

static size_t	my_counter(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**buff;
	size_t	i;
	size_t	j;
	size_t	count;

	if (s == NULL)
		return (NULL);
	printf("\nOK before my_counter\n");
	count = my_counter(s, c);	
	printf("\nOK before malloc char**\n");
	buff = (char**)malloc(sizeof(char) * (ft_strlen(s) + 1) * (count + 1));
	i = 0;
	printf("\nOK before mallocs char*\n");
	while (i <= count)
	{
		buff[i] = (char*)malloc((sizeof(char) * (ft_strlen(s) + 1)));
		i++;
		printf("\nOk malloc %zd\n", i);
	}
	i = 0;
	printf("\nOK before NULL test\n");
	if (buff == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != c)
		{
			printf("\nRemplissage i = %zd, j = %zd\n", i, j);
			buff[count][j] = s[i];
			i++;
			j++;
		}
		count++;
	}
	return (buff);
}
