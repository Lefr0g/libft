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
	size_t	len;

	if (s == NULL)
		return (0);
	while (s[*i] == c)
	   *i = *i + 1;
	while (s[*i] != '\0' && s[*i] != c)
		len++;
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**buff;
	size_t	count;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL)
		return (NULL);
	count = my_counter(s, c);
	buff = (char**)malloc(sizeof(char*) * count);
	if (buff == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (k < count)
	{
		j = my_strlenchar(&s[i], c, &i) + 1;
		buff[k] = (char*)malloc(sizeof(char) * j);
		if (buff[k] == NULL)
			return (NULL);
		if (k == count - 1)
			ft_strcpy(buff[k], "");
		else
			ft_strncpy(buff[k], &s[i], j);
		k++;
	}
	return (buff);
}
