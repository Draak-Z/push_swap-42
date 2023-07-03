/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:44:59 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/09 14:45:01 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	(void)*pile_b;
	if (*pile_a && (*pile_a)->next)
	{
		tmp = (*pile_a)->next;
		tmp2 = tmp->next;
		if (tmp2)
			tmp2->previous = (*pile_a);
		(*pile_a)->next = tmp2;
		(*pile_a)->previous = tmp;
		tmp->previous = 0;
		tmp->next = (*pile_a);
		(*pile_a) = tmp;
	}
}

void	sb(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	(void)*pile_a;
	if (*pile_b && (*pile_b)->next)
	{
		tmp = (*pile_b)->next;
		tmp2 = tmp->next;
		if (tmp2)
			tmp2->previous = (*pile_b);
		(*pile_b)->next = tmp2;
		(*pile_b)->previous = tmp;
		tmp->previous = 0;
		tmp->next = (*pile_b);
		(*pile_b) = tmp;
	}
}

void	ss(t_pile **pile_a, t_pile **pile_b)
{
	sa(pile_a, pile_b);
	sb(pile_a, pile_b);
}

void	pa(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if (*pile_b)
	{
		tmp = (*pile_b);
		(*pile_b) = (*pile_b)->next;
		tmp->next = 0;
		tmp->previous = 0;
		if (*pile_b)
			(*pile_b)->previous = 0;
		lstaddfront(pile_a, tmp);
	}
}

void	pb(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if (*pile_a)
	{
		tmp = (*pile_a);
		(*pile_a) = (*pile_a)->next;
		tmp->next = 0;
		tmp->previous = 0;
		if (*pile_a)
			(*pile_a)->previous = 0;
		lstaddfront(pile_b, tmp);
	}
}
