/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:01:11 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/09 17:06:23 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_b(int maillon, t_pile **pile_b, t_pile **pile_a, int i)
{
	if (maillon <= (lstsize(*pile_b) / 2))
	{
		i = 1;
		while (i++ < maillon)
		{
			rb(pile_a, pile_b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		i = lstsize(*pile_b);
		while (i-- >= maillon)
		{
			rrb(pile_a, pile_b);
			write(1, "rrb\n", 4);
		}
	}
}

void	check_param(t_pile **pile_b, int *nb_maillon)
{
	t_pile	*tmp;
	int		maillon;
	int		nb;

	tmp = *pile_b;
	maillon = 0;
	nb = -2147483648;
	while (tmp)
	{
		maillon++;
		if (tmp->nb >= nb)
		{
			*nb_maillon = maillon;
			nb = tmp->nb;
		}
		tmp = tmp->next;
	}
}

void	refill_a(t_pile **pile_a, t_pile **pile_b)
{
	int	maillon;

	while (*pile_b)
	{
		maillon = 0;
		check_param(pile_b, &maillon);
		if (lstsize(*pile_b) > 1)
			empty_b(maillon, pile_b, pile_a, 0);
		pa(pile_a, pile_b);
		write(1, "pa\n", 3);
	}
}
