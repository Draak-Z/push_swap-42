/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:42:56 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/10 15:02:17 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker3(t_pile **pile_a, t_pile **pile_b, char *buff)
{
	lstclear(pile_a);
	lstclear(pile_b);
	free(buff);
	return (write(2, "Error\n", 6));
}

int	checker2(t_pile **pile_a, t_pile **pile_b, char *buff)
{
	if (cmp(buff, "sa"))
		sa(pile_a, pile_b);
	else if (cmp(buff, "sb"))
		sb(pile_a, pile_b);
	else if (cmp(buff, "ss"))
		ss(pile_a, pile_b);
	else if (cmp(buff, "pa"))
		pa(pile_a, pile_b);
	else if (cmp(buff, "pb"))
		pb(pile_a, pile_b);
	else if (cmp(buff, "ra"))
		ra(pile_a, pile_b);
	else if (cmp(buff, "rb"))
		rb(pile_a, pile_b);
	else if (cmp(buff, "rr"))
		rr(pile_a, pile_b);
	else if (cmp(buff, "rra"))
		rra(pile_a, pile_b);
	else if (cmp(buff, "rrb"))
		rrb(pile_a, pile_b);
	else if (cmp(buff, "rrr"))
		rrr(pile_a, pile_b);
	else
		return (checker3(pile_a, pile_b, buff));
	return (0);
}

int	checker(t_pile **pile_a, t_pile **pile_b)
{
	int		ret;
	char	*buff;

	ret = 0;
	while (1)
	{
		ret = get_next_line(0, &buff);
		if (ret == 0)
		{
			free(buff);
			break ;
		}
		if (checker2(pile_a, pile_b, buff))
			return (1);
		free(buff);
	}
	ret = checker_pile(pile_a, pile_b);
	lstclear(pile_a);
	lstclear(pile_b);
	if (ret)
		return (write(2, "KO\n", 3));
	write(1, "OK\n", 3);
	return (0);
}

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = 0;
	pile_b = 0;
	if (check_pile(ac, av))
		return (1);
	if (ac <= 2)
	{
		if (ac == 2)
			write(1, "OK\n", 3);
		return (0);
	}
	if (fill_struct(&pile_a, av))
		return (1);
	if (checker(&pile_a, &pile_b))
		return (1);
	return (0);
}
