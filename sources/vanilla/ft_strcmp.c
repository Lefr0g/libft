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
