/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:15:22 by amulin            #+#    #+#             */
/*   Updated: 2016/04/07 14:17:19 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

void	ft_print_error(char *progname, char *arg, int errnum)
{
	if (!progname && !errnum)
	{
		ft_putstr_fd("Fatal error: you accidentally the whole program.\n", 2);
		ft_putstr_fd("            Just stay away from computers. Please.\n", 2);
	}
	else if (!progname)
	{
		ft_putstr_fd("Fatal error: ", 2);
		ft_putstr_fd(strerror(errnum), 2);
		ft_putstr_fd("\n", 2);
	}
	else
	{
		ft_putstr_fd(progname, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(arg, 2);
		if (errnum)
		{
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(strerror(errnum), 2);
		}
		ft_putstr_fd("\n", 2);
	}
}
