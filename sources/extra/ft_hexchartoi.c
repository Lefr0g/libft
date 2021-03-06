/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexchartoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:24:36 by amulin            #+#    #+#             */
/*   Updated: 2016/04/14 18:33:33 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

int	ft_hexchartoi(char c)
{
	if (!ft_ishexa(c))
		return (-1);
	if (ft_isalpha(c))
		return (ft_tolower(c) - 87);
	else
		return (c - 48);
}
