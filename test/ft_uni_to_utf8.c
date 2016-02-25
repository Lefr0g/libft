/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_to_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:59:39 by amulin            #+#    #+#             */
/*   Updated: 2016/02/25 18:56:33 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned int	ft_uni_to_utf8(wchar_t codepoint)
{
	unsigned char			in[4];
	unsigned char	lead_byte_2;
	unsigned char	lead_byte_3;
	unsigned char	lead_byte_4;
	unsigned char	cont_byte;
	unsigned int	output;
	unsigned char	buf;
	unsigned int	buf2;

	lead_byte_2 = 0xC0;
	lead_byte_3 = 0xE0;
	lead_byte_4 = 0xF0;
	cont_byte = 0x80;
	buf = 0;
	buf2 = 0;

	ft_memcpy(in, &codepoint, 4);
/*
	ft_putnbr(in[0]);
	ft_putchar('\n');
	ft_putnbr(in[1]);
	ft_putchar('\n');
	ft_putnbr(in[2]);
	ft_putchar('\n');
	ft_putnbr(in[3]);
	ft_putchar('\n');
*/
	if (codepoint <= 0x007F)
	{
		output = (unsigned int)codepoint;
	}
	else if (codepoint <= 0x07FF)
	{
		buf = (unsigned char)codepoint;
		buf = (unsigned char) (buf << 2) >> 2;
		output = (buf | cont_byte) << 8;

		buf = (unsigned char) codepoint >> 6;
		buf |= lead_byte_2;
		output |= buf;
	}
	else
		return (0);
	return (output);
}

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int	main(void)
{
	wchar_t			unicode;
	unsigned int	utf8;

	setlocale(LC_ALL, "");

	unicode = 0xE9;

	ft_putstr("Unicode = ");
	write(1, &unicode, 4);
	ft_putchar('\n');
	ft_print_memory(&unicode, 4);

	utf8 = ft_uni_to_utf8(unicode);

	ft_putstr("\nUTF-8 = ");
//	utf8 = 0xC3A9;
	write(1, &utf8, 4);
	ft_putchar('\n');
	ft_print_memory(&utf8, 4);
	ft_putchar('\n');
	printf("Before\n");
	printf("With printf : %lc\n", unicode);
	printf("After\n");

	return (0);
}
