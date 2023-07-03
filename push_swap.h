/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaudet <bmaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:44:50 by bmaudet           #+#    #+#             */
/*   Updated: 2021/06/09 16:09:00 by bmaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_pile
{
	int			nb;
	void		*next;
	void		*previous;
}				t_pile;

typedef struct s_var
{
	int		move;
	int		nb_move;
}			t_var;

t_pile	*lstnew(int nb);
void	lstaddback(t_pile **pile, t_pile *new);
void	lstaddfront(t_pile **pile, t_pile *new);
void	lstclear(t_pile **pile_a);
void	sa(t_pile **pile_a, t_pile **pile_b);
void	sb(t_pile **pile_a, t_pile **pile_b);
void	ss(t_pile **pile_a, t_pile **pile_b);
void	pa(t_pile **pile_a, t_pile **pile_b);
void	pb(t_pile **pile_a, t_pile **pile_b);
void	ra(t_pile **pile_a, t_pile **pile_b);
void	rb(t_pile **pile_a, t_pile **pile_b);
void	rr(t_pile **pile_a, t_pile **pile_b);
void	rra(t_pile **pile_a, t_pile **pile_b);
void	rrb(t_pile **pile_a, t_pile **pile_b);
void	rrr(t_pile **pile_a, t_pile **pile_b);
int		lstsize(t_pile *lst);
int		check_pile(int ac, char **av);
int		fill_struct(t_pile **pile_a, char **av);
int		check_arg(char *str, long int *count);
int		check_doublon(char **str);
int		cmp(char *s1, char *s2);
int		algo(t_pile **pile_a, int nb_param, int nbcluster);
int		checker(t_pile **pile_a, t_pile **pile_b);
int		ft_sqrt(int nb);
int		get_next_line(int fd, char **line);
int		check_return(char *str);
int		go_malloc(void **str, int taille);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		bruteforce(t_pile **pile_a);
int		checker_pile(t_pile **pile_a, t_pile **pile_b);
void	go_algo(t_pile **pile_a, int **maxnb, int nbcluster, int nbparam);
void	refill_a(t_pile **pile_a, t_pile **pile_b);
int		len(char *str);
void	writte(int i);
void	fill_ft(void **f);
#endif
