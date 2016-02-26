/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:44:07 by amulin            #+#    #+#             */
/*   Updated: 2016/02/26 15:09:29 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar(wchar_t c)
{
	unsigned int	utf;
	int				outlen;

	outlen = 0;
	utf = ft_uni_to_utf8(c);
	if (c <= 0x007F)
		outlen = 1;
	else if (c <= 0x7FF)
		outlen = 2;
	else if (c <= 0xFFFF)
		outlen = 3;
	else
		outlen = 4;
	write(1, &utf, outlen);
	return (outlen);
}
