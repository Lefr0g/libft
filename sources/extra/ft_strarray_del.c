/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 21:00:51 by amulin            #+#    #+#             */
/*   Updated: 2016/04/14 21:01:22 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

void	ft_strarray_del(char ***array)
{
	int		i;

	i = -1;
	while (array[0][++i])
		ft_strdel(&array[0][i]);
	ft_memdel((void**)array);
}
