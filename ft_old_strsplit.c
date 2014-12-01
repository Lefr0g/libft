/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 12:37:17 by amulin            #+#    #+#             */
/*   Updated: 2014/12/01 20:09:31 by amulin           ###   ########.fr       */
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
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	if (s[0] == c)
		count--;
//	printf("\nCount = %zd\n", count);
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**buff;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	count;

	if (s == NULL)
		return (NULL);
//	printf("\nOK before my_counter\n");
	count = my_counter(s, c);	
	printf("\nOK before malloc char**\n");
	buff = (char**)malloc(sizeof(char) * (ft_strlen(s) + 1) * (count + 1));
	if (buff == NULL)
		return (NULL);
	k = 0;
	printf("\nOK before mallocs char*\n");
	while (k <= count)
	{
		buff[k] = (char*)malloc((sizeof(char) * (ft_strlen(s) + 1)));
		if (buff[k] == NULL)
			return (NULL);
		k++;
		printf("\nOk malloc %zd\n", k);
	}
	i = 0;
	k = 0;
	printf("\nOK before fill loop\n");
	while (s[i] != '\0' && k <= count)
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
//			printf("\nRemplissage i = %zd, j = %zd, k = %zd\n", i, j, k);
			buff[k][j] = s[i];
			i++;
			j++;
		}
		buff[k][j] = '\0';
		k++;
//		printf("\nEnd or loop, k = %zd\n", k);
	}
//	buff[k][0] = '\0';
	if (s[i] == '\0')
	{
//		printf("\nException chaine vide");
		buff[0][0] = '\0';
	}
//	printf("\nEnd of string");
	return (buff);
}
