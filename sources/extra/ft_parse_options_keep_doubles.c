/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options_keep_doubles.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:40:47 by amulin            #+#    #+#             */
/*   Updated: 2016/07/28 19:45:24 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

/*
** This function does the same job as ft_parse_options, except that it doesn't
** clean double option flags from the resulting 'sorted' tab.
*/

/*
** Subfunction for ft_parse_options, dedicated to testing the validity of
** the 'tested' argument as an option, then duplicating it (if valid) into the
** program's 'stored' table.
** If the 'tested' argument is not a valid option, the function returns 1
*/

static int	get_opts(int *i, char **valid, char *tested, char **stored)
{
	int	j;
	int	match;

	j = -1;
	match = 0;
	while (valid[++j][0])
		if (!ft_strcmp(valid[j], tested) && (match = 1))
		{
			stored[*i] = ft_strdup(tested);
			(*i)++;
		}
	if (!match)
		return (1);
	return (0);
}

/*
** Subfunction for ft_parse_options that allocates sufficient memory to store
** all valid options into a string array.
** Notice that it will probably allocate more memory than necessary.
*/

static int	allocate_storage(char **tested, char ***stored)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tested[++i])
	{
		if (tested[i][0] == '-')
		{
			if (tested[i][1] == '-')
				j++;
			else
				j += ft_strlen(tested[i]);
		}
	}
	*stored = (char**)ft_memalloc(sizeof(char*) * (j + 1));
	if (!(*stored))
		return (1);
	return (0);
}

/*
** This function ensures options given as program arguments are supported,
** and retrieves supported options from the command line argument list.
** -
** 'tstd' (tested) is supposed to be main's argv, ideally a copy of it,  but it
** can be any string table ending with a NULL pointer. However the first string
** of the array won't be inspected.
** 'valid' is the string table of supported options, it must be terminated by
** an empty string.
** 'stored' is a pointer to an unallocated string table that will store the
** options validated by the function.
** -
** The function ignores 'tstd' strings unless they begin with a '-'
** Characters following a '-' are treated individually
** Characters following a '--' are treated as a single string
** Upon reading '--\0' the function stops.
** -
** For norme compliance, the flag indicating a '--\0' encounter was replaced by
** setting k (i[2]) to a negative value.
** -
** The function returns '\0' when all options are valid, '-' if a long option
** is invalid, or the char corresponding to an invalid short option.
** -
** Note: this function is a quick substitute to an upcoming (TODO)
** reimplementation of the cleaner getopt() and getopt_long() functions.
** -
** -
** ****************************************************************************
** ATTENTION : the function also removes the valid options from the 'tstd'
** string array. This will leave "holes" in the input array. Make sure to
** process this array correctly after calling ft_parse_options().
** ****************************************************************************
*/

char		ft_parse_options_keep_doubles(char **tstd, char **valid,
		char ***stored)
{
	int		i[3];
	char	buf[2];

	i[2] = 0;
	if (!(i[0] = 0) && allocate_storage(tstd, stored))
		return ('!');
	ft_bzero(buf, 2);
	while (tstd[++i[0]] && (i[2] = (tstd[i[0]][0] == '-' ? i[2] : -1)) >= 0)
	{
		if (ft_strlen(tstd[i[0]]) == 1)
			return (0);
		i[1] = 0;
		if (tstd[i[0]][0] && tstd[i[0]][1] == '-' && ft_strlen(tstd[i[0]]) > 3
				&& ((i[2] = !tstd[i[0]][2] ? -1 : i[2]) >= 0 || 1))
		{
			if (get_opts(&i[2], valid, &tstd[i[0]][2], *stored) && i[2] >= 0)
				return ('-');
		}
		else if (tstd[i[0]][1])
			while (tstd[i[0]][++i[1]] && (buf[0] = tstd[i[0]][i[1]]))
				if (get_opts(&i[2], valid, buf, *stored))
					return (buf[0]);
		ft_strclr(tstd[i[0]]);
	}
	return (0);
}
