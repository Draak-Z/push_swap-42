/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:45:29 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/09 16:07:20 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkbrute(int *tab, int *reset, t_pile **pile_a)
{
	t_pile	*pile_b;
	void	(*f[12])(t_pile**, t_pile**);
	int		i;
	int		j;

	fill_ft((void **)&f);
	pile_b = 0;
	i = 0;
	j = 0;
	while (tab[i])
		f[tab[i++]](pile_a, &pile_b);
	i = checker_pile(pile_a, &pile_b);
	while (pile_b)
		pa(pile_a, &pile_b);
	pile_b = *pile_a;
	while (pile_b)
	{
		pile_b->nb = reset[j++];
		pile_b = pile_b->next;
	}
	if (i)
		return (1);
	return (0);
}

int	*bruteforce3(int *tab, int *reset, t_pile **pile_a)
{
	int	i;

	while (!tab[8])
	{
		i = 0;
		if (!checkbrute(tab, reset, pile_a))
		{
			free(reset);
			return (tab);
		}
		tab[0]++;
		while (tab[i] == 12)
		{
			tab[i] = 1;
			tab[i + 1]++;
			i++;
		}
	}
	return (0);
}

int	*bruteforce2(t_pile **pile_a)
{
	t_pile	*tmp;
	int		*tab;
	int		*reset;
	int		i;

	i = 0;
	if (go_malloc((void *)&reset, (sizeof(int) * lstsize(*pile_a))))
		return (0);
	tmp = *pile_a;
	while (tmp)
	{
		reset[i++] = tmp->nb;
		tmp = tmp->next;
	}
	i = 0;
	if (go_malloc((void *)&tab, (sizeof(int) * 9)))
	{
		free(reset);
		return (0);
	}
	while (i < 9)
		tab[i++] = 0;
	return (bruteforce3(tab, reset, pile_a));
}

int	bruteforce(t_pile **pile_a)
{
	int		i;
	int		*tab;

	i = -1;
	tab = bruteforce2(pile_a);
	if (!tab)
		return (1);
	while (tab[++i])
		writte(tab[i]);
	free(tab);
	return (0);
}
