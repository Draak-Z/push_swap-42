/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:36:24 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/07 19:37:03 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	(void)*pile_b;
	if (*pile_a && (*pile_a)->next)
	{
		tmp2 = *pile_a;
		*pile_a = (*pile_a)->next;
		(*pile_a)->previous = 0;
		tmp = (*pile_a);
		while (tmp->next)
			tmp = tmp->next;
		tmp2->previous = tmp;
		tmp2->next = 0;
		tmp->next = tmp2;
	}
}

void	rb(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	(void)*pile_a;
	if (*pile_b && (*pile_b)->next)
	{
		tmp2 = *pile_b;
		*pile_b = (*pile_b)->next;
		(*pile_b)->previous = 0;
		tmp = (*pile_b);
		while (tmp->next)
			tmp = tmp->next;
		tmp2->previous = tmp;
		tmp2->next = 0;
		tmp->next = tmp2;
	}
}

void	rr(t_pile **pile_a, t_pile **pile_b)
{
	ra(pile_a, pile_b);
	rb(pile_a, pile_b);
}

void	rra(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	(void)*pile_b;
	if (*pile_a && (*pile_a)->next)
	{
		tmp = (*pile_a);
		while (tmp->next)
			tmp = tmp->next;
		tmp2 = tmp->previous;
		tmp2->next = 0;
		tmp->next = (*pile_a);
		(*pile_a)->previous = tmp;
		tmp->previous = 0;
		(*pile_a) = (*pile_a)->previous;
	}
}

void	rrb(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	(void)*pile_a;
	if (*pile_b && (*pile_b)->next)
	{
		tmp = (*pile_b);
		while (tmp->next)
			tmp = tmp->next;
		tmp2 = tmp->previous;
		tmp2->next = 0;
		tmp->next = (*pile_b);
		(*pile_b)->previous = tmp;
		tmp->previous = 0;
		(*pile_b) = (*pile_b)->previous;
	}
}
