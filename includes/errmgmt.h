/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errmgmt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:34:24 by amulin            #+#    #+#             */
/*   Updated: 2016/04/07 20:22:56 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRMGMT_H
# define ERRMGMT_H

# include "libft.h"
# include <errno.h>

void	ft_print_error(char *progname, char *arg, int errnum);

#endif
