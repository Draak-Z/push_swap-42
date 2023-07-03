/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:43:34 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/07 18:53:35 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*lstnew(int nb)
{
	t_pile	*n;

	n = malloc(sizeof(t_pile));
	if (!n)
		return (0);
	n->nb = nb;
	n->next = 0;
	n->previous = 0;
	return (n);
}

void	lstaddback(t_pile **pile, t_pile *new)
{
	t_pile	*tmp;

	if (pile)
	{
		if ((*pile) == 0)
			*pile = new;
		else
		{
			tmp = *pile;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->previous = tmp;
		}
	}
}

void	lstaddfront(t_pile **pile, t_pile *new)
{
	if (pile)
	{
		if ((*pile) == 0)
			(*pile) = new;
		else
		{
			new->next = *pile;
			(*pile)->previous = new;
			(*pile) = new;
		}
	}
}

void	lstclear(t_pile **pile_a)
{
	t_pile	*tmp;

	if (*pile_a)
	{
		while (*pile_a)
		{
			tmp = *pile_a;
			*pile_a = tmp->next;
			if (tmp)
				free(tmp);
		}
		pile_a = 0;
	}
}

int	lstsize(t_pile *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
