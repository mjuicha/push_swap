/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:05:57 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/09 01:56:22 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	x;

	x = 0;
	while (s1[x] && s2[x] && s1[x] == s2[x])
		x++;
	return (s1[x] - s2[x]);
}

int	correct_input(char *s)
{
	int	i;

	if (ft_strcmp(s, "sa") == 0 || ft_strcmp(s, "sb") == 0
		|| ft_strcmp(s, "ss") == 0)
		i = 1;
	else if (ft_strcmp(s, "ra") == 0 || ft_strcmp(s, "rb") == 0
		|| ft_strcmp(s, "rr") == 0)
		i = 2;
	else if (ft_strcmp(s, "rra") == 0 || ft_strcmp(s, "rrb") == 0
		|| ft_strcmp(s, "rrr") == 0)
		i = 3;
	else if (ft_strcmp(s, "pa") == 0 || ft_strcmp(s, "pb") == 0)
		i = 4;
	else
		i = 0;
	return (i);
}

void	do_it(char *s, t_stack **a, t_stack **b, int i)
{
	if (i == 1)
		doswap(s, a, b);
	else if (i == 2)
		dorot(s, a, b);
	else if (i == 3)
		dorrot(s, a, b);
	else if (i == 4)
		dopush(s, a, b);
}

void	my_algo(t_stack **a, t_stack **b)
{
	char	*s;
	int		i;

	s = get_next_line(0);
	while (s != NULL && correct_input(s))
	{
		i = correct_input(s);
		if (!i)
			break ;
		do_it(s, a, b, i);
		free(s);
		s = get_next_line(0);
	}
	if (s && !correct_input(s))
		write(2, "Error\n", 6);
	else if (check_asc(a) == 0 && *b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(s);
}
