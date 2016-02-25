/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:44:07 by amulin            #+#    #+#             */
/*   Updated: 2016/02/25 21:46:18 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	unsigned int	utf;

	utf = ft_uni_to_utf8(c);
	if (c <= 0x007F)
		write(1, &utf, 1);
	else if (c <= 0x7FF)
		write(1, &utf, 2);
	else if (c <= 0xFFFF)
		write(1, &utf, 3);
	else
		write(1, &utf, 4);
}
