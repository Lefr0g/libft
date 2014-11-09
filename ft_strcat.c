/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:                                          #+#    #+#             */
/*   Updated:                                         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
#include "libft.h"
#include <stdio.h>

char	*ft_strcat(char *dest, const char *src)
{
	int origin;
	int i;

	i = 0;
	origin = 0;
	printf("<<< DEBUG >>> ft_strcat : Arrivee devant la boucle 1");
	while (dest[origin] != '\0')
	{
		printf("<<< DEBUG >>> ft_strcat : Boucle 1, iteration %d", origin);
		origin++;
	}
	while (src[i] != '\0')
	{
		printf("<<< DEBUG >>> ft_strcat : Boucle 2, iteration %d", i);
		dest[origin + i] = src[i];
		i++;
	}
	dest[origin + i] = '\0';
	return (dest);
}

int	main(void)
{
	char *source;
	char *destination;

	printf("<<< DEBUG >>> main : Debut des Mallocs"); 
	source = (char*)malloc(sizeof(char) * 42);
	destination = (char*)malloc(sizeof(char) * 42);
	printf("<<< DEBUG >>> main : Fin des Mallocs"); 
	source = "ABCDE";
	destination = "01234";
	destination = ft_strcat(destination, source);
	return (0);
}
