/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_to_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:59:39 by amulin            #+#    #+#             */
/*   Updated: 2016/02/25 19:57:29 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned int	ft_uni_to_utf8(wchar_t codepoint)
{
	unsigned char	lead_byte;
	unsigned char	cont_byte;
	unsigned int	output;
	unsigned char	buf;

	cont_byte = 0x80;
	buf = 0;
	output = 0;
	if (codepoint <= 0x007F)
		output = (unsigned int)codepoint;
	else if (codepoint <= 0x1FFFFF)
	{
		buf = (unsigned char) (codepoint << 2) >> 2;
		output = (buf | cont_byte) << 8;
		if (codepoint <= 0x7FF)
			output |= (codepoint >> 6) | 0xC0;
		else
		{
			buf = (unsigned char) codepoint >> 6;
			output = output << 8;
			output |= (buf | cont_byte) << 8;
			if (codepoint <= 0xFFFF)
			{
				lead_byte = 0xE0;
				buf = codepoint >> 12;
				buf |= lead_byte;
				output |= buf;
			}
			else
			{
				lead_byte = 0xF0;
				buf = codepoint >> 12;
				buf = (unsigned char) (buf << 2) >> 2;
				output = output << 8;
				output |= (buf | cont_byte) << 8;
				buf = codepoint >> 20;
				buf |= lead_byte;
				output |= buf;
			}
		}
	}
	return (output);
}

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

void	compare(wchar_t unicode)
{
	unsigned int	utf8;

	ft_putstr("Unicode = ");
	ft_puthex(unicode, "min");
	utf8 = ft_uni_to_utf8(unicode);
	ft_putstr("\nUTF-8 = ");
	write(1, &utf8, 4);
	printf("\nWith printf : %lc\n", unicode);
	ft_print_memory(&utf8, 4);
	ft_putchar('\n');
}

int	main(void)
{
	setlocale(LC_ALL, "");

	compare(0xE9);
	compare(0x7F7);
	compare(0x20AC);
	compare(0x20012);
	return (0);
}
