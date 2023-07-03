/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:57:26 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/09 16:55:46 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_move(int move1, int move2, int *move, int *sens)
{
	if (move1 <= move2)
	{
		(*move) = move1;
		*sens = 1;
	}
	else
	{
		(*move) = (move2 + 1);
		*sens = -1;
	}
}

void	check_sens(int *sens, int *move, t_pile **pile_a, int limit)
{
	t_pile	*tmp;
	int		move1;
	int		move2;

	tmp = *pile_a;
	move1 = 0;
	move2 = 0;
	while (tmp && tmp->nb > limit)
	{
		move1++;
		tmp = tmp->next;
	}
	if (!tmp)
	{
		*sens = 0;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	while (tmp && tmp->nb > limit)
	{
		move2++;
		tmp = tmp->previous;
	}
	assign_move(move1, move2, move, sens);
}

void	fill_b(t_pile **pile_a, t_pile **pile_b, int nbparam, int limit)
{
	int	sens;
	int	move;

	while (nbparam--)
	{
		check_sens(&sens, &move, pile_a, limit);
		if (sens)
		{
			while (move--)
			{
				if (sens > 0)
				{
					write(1, "ra\n", 3);
					ra(pile_a, pile_b);
				}
				else
				{
					write(1, "rra\n", 4);
					rra(pile_a, pile_b);
				}
			}
			write(1, "pb\n", 3);
			pb(pile_a, pile_b);
		}
	}
}

void	go_algo(t_pile **pile_a, int **maxnb, int nbcluster, int nbparam)
{
	t_pile	*pile_b;
	int		i;

	i = 0;
	pile_b = 0;
	if (checker_pile(pile_a, &pile_b))
	{
		while (nbcluster--)
			fill_b(pile_a, &pile_b, nbparam, (*maxnb)[i++]);
		refill_a(pile_a, &pile_b);
		lstclear(&pile_b);
	}
	free((*maxnb));
}
