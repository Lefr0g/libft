/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_utf8len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 19:09:59 by amulin            #+#    #+#             */
/*   Updated: 2016/03/18 19:16:00 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wchar_utf8len(wchar_t const wc)
{
	size_t	len;

	if (wc <= 0x007F)
		len = 1;
	else if (wc <= 0x7FF)
		len = 2;
	else if (wc <= 0xFFFF)
		len = 3;
	else
		len = 4;
	return (len);
}
