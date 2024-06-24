/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hypo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:02:30 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/23 19:16:14 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	done_a(t_stack **a, t_stack *node, int *pi, t_stack **b)
{
	t_stack	**sta;
	int		size_a;
	int		c;

	if (node == NULL || *a == NULL)
		return ;
	sta = a;
	c = *pi;
	size_a = count_stack(sta);
	while (*sta != NULL && (*sta)->value != node->value)
	{
		if (node == NULL)
			return ;
		else if (node->index > size_a / 2 && br(*a, *b))
			rrr1(sta, a, b, &c);
		else if (node->index <= size_a / 2 && br1(*a, *b))
			rr1(sta, a, b, &c);
		else if (node->index <= size_a / 2)
			ra(sta, &c, 0);
		else if (node->index > size_a / 2)
			rra(sta, &c, 0);
	}
	*a = *sta;
	*pi = c;
}

void	done_b(t_stack **a, t_stack **b, int *pi)
{
	t_stack	**stb;
	t_stack	*sec;
	int		size_b;
	int		c;

	stb = b;
	c = *pi;
	sec = cheap_max((*a)->value, b);
	if (sec == NULL)
		return ;
	size_b = count_stack(stb);
	while (*stb != NULL && sec->value != (*stb)->value)
	{
		if (sec == NULL)
			break ;
		else if (sec->index <= size_b / 2)
			rb(stb, &c, 0);
		else if (sec->index > size_b / 2)
			rrb(stb, &c, 0);
	}
	*pi = c;
}
