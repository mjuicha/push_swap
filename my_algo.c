/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:05:57 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/25 17:44:18 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_input(char *s)
{
	int	i;

	if (strcmp(s, "sa") == 0 || strcmp(s, "sb") == 0 || strcmp(s, "ss") == 0)
		i = 1;
	else if (strcmp(s, "ra") == 0 || strcmp(s, "rb") == 0
		|| strcmp(s, "rr") == 0)
		i = 2;
	else if (strcmp(s, "rra") == 0 || strcmp(s, "rrb") == 0
		|| strcmp(s, "rrr") == 0)
		i = 3;
	else if (strcmp(s, "pa") == 0 || strcmp(s, "pb") == 0)
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
