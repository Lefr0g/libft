/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:02:20 by amulin            #+#    #+#             */
/*   Updated: 2014/11/05 15:21:13 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("\n********** TEST - DEBUT DU TEST **********\n");
	printf("\n    ***** TEST 1 - ft_putchar.c : *****\n");
	ft_putchar('A');
	ft_putchar('\n');
	ft_putchar('1');
	ft_putchar('\n');
	printf("\n    ***** TEST 2 - ft_putstr.c : *****\n");
	ft_putstr("Hello World! 1234567890 qwertyuiopasdfghjklzxcvbnm <>/#$ \n");
	ft_putstr("Looking good...\n");
	printf("\n    ***** TEST 3 - ft_putnbr.c : *****\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(999999999);
	printf("\n");
	ft_putnbr(-999999999);
	printf("\n");
	printf("\n    ***** TEST 4 - ft_putchar_fd.c : *****\n");
	ft_putchar_fd('1', 1);
	printf("\n");
	ft_putchar_fd('2', 2);
	printf("\n");
	printf("\n*********** TEST - FIN DU TEST ***********\n");
	return (0);
}
