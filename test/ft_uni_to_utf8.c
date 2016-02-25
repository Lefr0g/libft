/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_to_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:59:39 by amulin            #+#    #+#             */
/*   Updated: 2016/02/25 20:29:34 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned int	ft_uni_to_utf8(wchar_t codepoint)
{
	unsigned char	cont_byte;
	unsigned int	output;

	if ((output = 0) && codepoint <= 0x007F)
		output = (unsigned int)codepoint;
	else if ((cont_byte = 0x80) && codepoint <= 0x1FFFFF)
	{
		output = (((unsigned char)(codepoint << 2) >> 2) | cont_byte) << 8;
		if (codepoint <= 0x7FF)
			output |= (codepoint >> 6) | 0xC0;
		else
		{
			output <<= 8;
			output |= (unsigned char)((codepoint >> 6) | cont_byte) << 8;
			if (codepoint <= 0xFFFF)
				output |= (codepoint >> 12) | 0xE0;
			else
			{
				output <<= 8;
				output |= (unsigned char)((codepoint >> 12) | cont_byte) << 8;
				output |= (codepoint >> 20) | 0xF0;
			}
		}
	}
	return (output);
}
