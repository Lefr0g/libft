#include "libft_extra.h"

/*
**	This function reverses the order by swapping 'prev' and 'next'
**	for each element
*/

void	ft_lstflip(t_list **alst)
{
	t_list	*buf;
	t_list	*tmp;

	if (alst && *alst)
	{
		buf = *alst;
		while (buf)
		{
			tmp = buf->next;
			buf->next = buf->prev;
			buf->prev = tmp;
			buf = buf->prev;
			if (buf)
				*alst = buf;
		}
	}
}


