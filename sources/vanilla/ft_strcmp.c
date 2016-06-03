/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:42:00 by amulin            #+#    #+#             */
/*   Updated: 2016/06/03 19:53:27 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		a = s1[i];
		b = s2[i];
		if (a > b)
			return (1);
		else if (a < b)
			return (-1);
		i++;
	}
	return (0);
}
*/

#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	len;
	int	ret;

	len = (ft_strlen(s1) > ft_strlen(s2)) ? ft_strlen(s2) : ft_strlen(s1);
	i = -1;
	while (++i < len)
		if ((ret = s1[i] - s2[i]))
			return (ret);
	return (s1[i] - s2[i]);
}
