/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_dup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 20:59:07 by amulin            #+#    #+#             */
/*   Updated: 2016/04/14 21:00:11 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

char	**ft_strarray_dup(char **src)
{
	int		i;
	char	**buf;

	i = 0;
	while (src[i])
		i++;
	if (!(buf = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = -1;
	while (src[++i])
		if (!(buf[i] = ft_strdup(src[i])))
			return (NULL);
	return (buf);
}
