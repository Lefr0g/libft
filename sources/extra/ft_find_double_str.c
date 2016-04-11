/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_double_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:10:50 by amulin            #+#    #+#             */
/*   Updated: 2016/04/11 13:14:39 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Subfunction for ft_parse_options, designed to avoid doubles in the
** 'stored' string table.
** If found, the function returns a pointer to the double in the haystack
*/

char	*ft_find_double_str(char *needle, char **haystack)
{
	int	i;

	i = -1;
	while (haystack[++i])
		if (!ft_strcmp(needle, haystack[i]))
			return (haystack[i]);
	return (NULL);
}
