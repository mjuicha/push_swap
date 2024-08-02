/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:26:42 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 19:34:41 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*loop(t_stack *sta, int *pi, t_stack **a, t_stack **b)
{
	t_stack	*stb;
	t_stack	*node;
	t_stack	*winner_node;
	int		i;
	int		c;

	stb = copy_stack(*b);
	node = NULL;
	winner_node = NULL;
	i = 1;
	c = *pi;
	while (sta != NULL && i <= count_stack(a))
	{
		refill(a, b, &sta, &stb);
		node = choosing(&sta, i++);
		done_a(&sta, node, &c);
		done_b(&sta, &stb, &c);
		if (winner_node == NULL || c > winner_node->best_score)
			winner_node->best_score = new_winner(node, &winner_node, &c);
		refill(a, b, &sta, &stb);
		c = *pi;
	}
	return (free_stacks(sta, stb), winner_node);
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
