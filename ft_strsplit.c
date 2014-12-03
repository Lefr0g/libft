/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 20:10:47 by amulin            #+#    #+#             */
/*   Updated: 2014/12/01 21:10:10 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	void	my_varsetzero(size_t *i)
{
	size_t	k;

	k = 0;
	while (k <= 3)
	{
		i[k] = 0;
		k++;
	}
}

static size_t	my_counter(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	if (s[0] == c && count > 1)
		count--;
	return (count);
}

static size_t	my_strlenchar(char const *s, char c, size_t *i)
{
	size_t	x;
	size_t	len;

	len = 0;
	x = *i;
	if (s == NULL)
		return (0);
	while (s[x] == c)
		x++;
	while (s[x] != '\0' && s[x] != c)
	{
		len++;
		x++;
	}
	*i = x;
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**buff;
	size_t	i[4];

	if (s == NULL)
		return (NULL);
	i[0] = my_counter(s, c);
	printf("\ni[0] = %zd\n", i[0]);
	buff = (char**)malloc(sizeof(char*) * i[0]);	
	if (buff == NULL)
		return (NULL);
	my_varsetzero(i);
	while (i[3] <= i[0])
	{
		i[2] = my_strlenchar(s, c, &i[1]);
		printf("\ni[0] = %zd, i[1] = %zd, i[2] = %zd, i[3] = %zd\n", i[0], i[1], i[2], i[3]);
		buff[i[3]] = (char*)malloc(sizeof(char) * (i[2] + 1));
		if (buff[i[3]] == NULL)
			return (NULL);
		if (i[3] == i[0])
			ft_strcpy(buff[i[3]], "");
		else
		{
			ft_strncpy(buff[i[3]], &s[i[1] - i[2]], i[2]);
			ft_bzero(&buff[i[3]][i[1] + 1], 1);
		}
		i[3]++;
	}
	return (buff);
}
