/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:21:52 by amulin            #+#    #+#             */
/*   Updated: 2016/06/03 19:37:34 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

/*
** Subfunction for ft_lstsort. This is the code for element removal
** and repositioning.
*/

static int	sub_elemmove(t_list **alst, t_list **run, t_list **ref, int ofst)
{
	t_list	*pos;

	pos = NULL;
	pos = (*run)->next;
	if (!ft_lstdetach(*run))
		return (1);
	while (*ref)
	{
		if (ft_strcmp((char*)((*ref)->content + ofst), (char*)((*run)->content + ofst)) < 0)
		{
			ft_lstinsertright(*run, *ref);
			*ref = NULL;
		}
		else if (!(*ref = (*ref)->prev))
			ft_lstadd(alst, *run);
	}
	if ((*run = pos))
		*ref = (*run)->prev;
	else
		*ref = NULL;
	return (0);
}

/*
** Cette fonction doit pouvoir realiser un tri par insersion sur la liste passee
** en parametre, en utilisant comme critere l'element de la structure 'content'
** designe par son decalage par rapport au pointeur sur 'content'.
** *
** Le mecanisme est le meme que pour ft_lstsort_int(), a la difference qu'ici le
** tri se fait de maniere lexicographique
*/

int			ft_lstsort_str(t_list **alst, int content_offset)
{
	t_list			*run_ptr;
	t_list			*ref_ptr;

	if (!alst || !(*alst) || !(*alst)->next)
		return (1);
	ref_ptr = *alst;
	run_ptr = ref_ptr->next;
	while (run_ptr)
	{
		if (ft_strcmp((char*)(ref_ptr->content + content_offset),
					(char*)(run_ptr->content + content_offset)) > 0)
		{
			if (sub_elemmove(alst, &run_ptr, &ref_ptr, content_offset))
				return (1);
		}
		else
		{
			run_ptr = run_ptr->next;
			ref_ptr = ref_ptr->next;
		}
	}
	return (0);
}
