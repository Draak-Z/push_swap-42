/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:47:53 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/07 19:37:08 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

int	go_malloc(void **str, int taille)
{
	(*str) = malloc(taille);
	if (str)
		return (0);
	return (1);
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	rra(pile_a, pile_b);
	rrb(pile_a, pile_b);
}

int	checker_pile(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	int		nb;

	if (*pile_b)
		return (1);
	tmp = *pile_a;
	nb = tmp->nb;
	while (tmp)
	{
		if (nb > tmp->nb)
			return (1);
		nb = tmp->nb;
		tmp = tmp->next;
	}
	return (0);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
