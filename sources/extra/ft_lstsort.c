/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:52:14 by amulin            #+#    #+#             */
/*   Updated: 2016/06/09 18:51:22 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

/*
** Subfunction for ft_lstsort. This is the code for element removal
** and repositioning.
*/

static t_list		*sub_elemmove(t_list **run, t_list **ref, int ofst,
		int (*compare)(void*, void*))
{
	t_list	*pos;
	t_list	*alst;

	alst = *ref;
	while (alst->prev)
		alst = alst->prev;
	pos = (*run)->next;
	if (!ft_lstdetach(*run))
		return (NULL);
	while (*ref)
	{
		if (compare((void*)((*ref)->content + ofst),
					(void*)((*run)->content + ofst)) <= 0)
		{
			ft_lstinsertright(*run, *ref);
			*ref = NULL;
		}
		else if (!(*ref = (*ref)->prev))
			ft_lstadd(&alst, *run);
	}
	if ((*run = pos))
		*ref = (*run)->prev;
	else
		*ref = NULL;
	return (alst);
}

/*
** Cette fonction doit pouvoir realiser un tri par insersion sur la liste passee
** en parametre, en utilisant comme critere contenu du pointeur designe par
** son decalage par rapport au pointeur sur 'content'
** La comparaison entre les 2 valeurs est effectuee par la fonction dont le
** pointeur est donne en parametre.
** Cette fonction a l'avantage d'etre generique, elle est totalement insensible
** au type de donnees a comparer.
** *
** Cette fonction de tri a ete creee dans le cadre du projet ft_ls
*/

int					ft_lstsort(t_list **alst, int content_offset,
		int (*compare)(void*, void*))
{
	t_list			*run_ptr;
	t_list			*ref_ptr;

	if (!alst || !(*alst) || !(*alst)->next)
		return (1);
	ref_ptr = *alst;
	run_ptr = ref_ptr->next;
	while (run_ptr)
	{
		if (compare((void*)(ref_ptr->content + content_offset),
					(void*)(run_ptr->content + content_offset)) > 0)
		{
			if (!(*alst = sub_elemmove(&run_ptr, &ref_ptr,
							content_offset, compare)))
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
