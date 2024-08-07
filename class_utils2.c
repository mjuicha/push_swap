/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:41:20 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 18:27:15 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	refill(t_stack **a, t_stack **b, t_stack **sa, t_stack **sb)
{
	t_stack	*sta;
	t_stack	*stb;

	sta = *sa;
	stb = *sb;
	free_stack(sta);
	free_stack(stb);
	sta = copy_stack(*a);
	stb = copy_stack(*b);
	*sa = sta;
	*sb = stb;
}

int	new_winner(t_stack *node, t_stack **w, int *pt)
{
	t_stack	*winner_node;
	int		c;

	winner_node = *w;
	c = *pt;
	free_stack(winner_node);
	winner_node = copy_stack(node);
	*w = winner_node;
	return (c);
}

void	free_stacks(t_stack *sta, t_stack *stb)
{
	free_stack(sta);
	free_stack(stb);
}
