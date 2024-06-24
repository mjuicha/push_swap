/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:26:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/24 18:24:34 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*loop(t_stack *sta, int *pi, t_stack **a, t_stack **b)
{
	t_stack	*stb;
	t_stack	*node;
	t_stack	*winner_node;
	int		tr;
	int		i;
	int		c;

	stb = copy_stack(*b);
	node = NULL;
	winner_node = NULL;
	tr = -1;
	i = 1;
	c = *pi;
	while (sta != NULL && i <= count_stack(a))
	{
		refill(a, b, &sta, &stb);
		node = choosing(&sta, i);
		done_a(&sta, node, &c, &stb);
		done_b(&sta, &stb, &c);
		if (tr == -1 || c > tr)
			tr = new_winner(node, &winner_node, &c);
		refill(a, b, &sta, &stb);
		c = *pi;
		i++;
	}
	return (free_stacks(sta, stb), winner_node);
}

t_stack	*store_stack(t_stack *new)
{
	static t_stack	*stored = NULL;

	stored = NULL;
	if (new != NULL)
		stored = new;
	return (stored);
}

int	init(t_stack **sa, t_stack **a, t_stack **b)
{
	t_stack	*sta;

	sta = copy_stack(*a);
	give_index(a);
	give_index(b);
	*sa = sta;
	if (sa == NULL)
		return (1);
	return (0);
}
