/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:45:12 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/09 15:59:37 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	writte(int i)
{
	if (i == 1)
		write(1, "sa\n", 3);
	if (i == 2)
		write(1, "sb\n", 3);
	if (i == 3)
		write(1, "ss\n", 3);
	if (i == 4)
		write(1, "pa\n", 3);
	if (i == 5)
		write(1, "pb\n", 3);
	if (i == 6)
		write(1, "ra\n", 3);
	if (i == 7)
		write(1, "rb\n", 3);
	if (i == 8)
		write(1, "rr\n", 3);
	if (i == 9)
		write(1, "rra\n", 4);
	if (i == 10)
		write(1, "rrb\n", 4);
	if (i == 11)
		write(1, "rrr\n", 4);
}

void	fill_ft(void **f)
{
	(f)[0] = 0;
	(f)[1] = &sa;
	(f)[2] = &sb;
	(f)[3] = &ss;
	(f)[4] = &pa;
	(f)[5] = &pb;
	(f)[6] = &ra;
	(f)[7] = &rb;
	(f)[8] = &rr;
	(f)[9] = &rra;
	(f)[10] = &rrb;
	(f)[11] = &rrr;
}
