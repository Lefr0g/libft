/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 19:56:29 by amulin            #+#    #+#             */
/*   Updated: 2016/06/03 17:31:11 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

/*
**	Compares 2 ints, returns the biggest
*/

int	ft_getmin(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
