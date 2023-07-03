/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:42:43 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/10 14:54:03 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_limit(t_pile **pile_a, int nbparam, int ic)
{
	int		nb;
	int		place;
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = *pile_a;
	nb = -2147483648;
	while (tmp)
	{
		place = 0;
		tmp2 = *pile_a;
		while (tmp2)
		{
			if (tmp->nb <= tmp2->nb)
				place++;
			tmp2 = tmp2->next;
		}
		if (place <= (nbparam * ic) - 1
			&& place > nbparam * (ic - 1) && nb < tmp->nb)
			nb = tmp->nb;
		tmp = tmp->next;
	}
	return (nb);
}

void	fill_limit(int **maxnb, t_pile **pile_a, int nbcluster, int nbparam)
{
	int	i;
	int	j;
	int	ic;
	int	tmp;

	i = -1;
	ic = 1;
	while (++i < nbcluster)
		(*maxnb)[i] = check_limit(pile_a, nbparam, ic++);
	i = -1;
	while (++i < nbcluster)
	{
		j = -1;
		while (++j < nbcluster - 1)
		{
			if ((*maxnb)[j] > (*maxnb)[j + 1])
			{
				tmp = (*maxnb)[j + 1];
				(*maxnb)[j + 1] = (*maxnb)[j];
				(*maxnb)[j] = tmp;
			}
		}
	}
}

int	algo(t_pile **pile_a, int nb_param, int nbcluster)
{
	int	nbincluster;
	int	*maxnb;

	if (nb_param <= 5)
	{
		if (bruteforce(pile_a))
		{
			lstclear(pile_a);
			return (1);
		}
	}
	else
	{
		nbcluster = (nb_param / (ft_sqrt(nb_param) * 2));
		nbincluster = nb_param / nbcluster + 1;
		if (go_malloc((void *)&maxnb, (sizeof(int) * nbcluster)))
		{
			lstclear(pile_a);
			return (write(2, "Error\n", 6));
		}
		fill_limit(&maxnb, pile_a, nbcluster, nbincluster);
		go_algo(pile_a, &maxnb, nbcluster, nbincluster);
	}
	lstclear(pile_a);
	return (0);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;

	pile_a = 0;
	if (check_pile(ac, av))
		return (1);
	if (ac <= 2)
		return (0);
	if (fill_struct(&pile_a, av))
		return (1);
	if (algo(&pile_a, (ac - 1), 0))
		return (1);
	return (0);
}
