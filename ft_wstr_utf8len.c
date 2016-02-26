/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_utf8len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:40:24 by amulin            #+#    #+#             */
/*   Updated: 2016/02/26 16:42:47 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstr_utf8len(const wchar_t *wstr)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 0x007F)
			len += 1;
		else if (wstr[i] <= 0x7FF)
			len += 2;
		else if (wstr[i] <= 0xFFFF)
			len += 3;
		else
			len += 4;
		i++;
	}
	return (len);
}
