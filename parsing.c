/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:44:39 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/10 15:06:33 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

int	check_doublon(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[++i])
	{
		j = 0;
		while (str[++j])
		{
			if (i != j)
				if (cmp(str[i], str[j]))
					return (write(2, "Error\n", 6));
		}
	}
	return (0);
}

int	check_arg(char *str, long *count)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && i < 12)
		(*count) = (*count) * 10 + str[i++] - '0';
	(*count) *= sign;
	if ((*count) < -2147483648 || (*count) > 2147483647)
		return (1);
	return (0);
}

int	fill_struct(t_pile **pile_a, char **av)
{
	int		i;
	long	nb;

	i = 0;
	while (av[++i])
	{
		nb = 0;
		if (check_arg(av[i], &nb))
		{
			lstclear(pile_a);
			return (write(2, "Error\n", 6));
		}
		lstaddback(pile_a, lstnew((int)nb));
	}
	return (0);
}

int	check_pile(int ac, char **av)
{
	int		i;
	long	j;

	j = 0;
	while (av[++j])
	{
		i = -1;
		if (av[j][0] != '-' && !(av[j][0] >= '0' && av[j][0] <= '9'))
			return (write(2, "Error\n", 6));
		if (av[j][0] == '-')
			i++;
		while (av[j][++i])
			if (!(av[j][i] >= '0' && av[j][i] <= '9'))
				return (write(2, "Error\n", 6));
	}
	if (ac == 2)
	{
		j = 0;
		if (check_arg(av[1], &j))
			return (write(2, "Error\n", 6));
		return (0);
	}
	if (check_doublon(av))
		return (1);
	return (0);
}
