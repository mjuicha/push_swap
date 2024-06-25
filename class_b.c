/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:51:53 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/25 16:38:35 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*clever_chosing(t_stack **a, t_stack **b, int *pi)
{
	t_stack	*sta;
	t_stack	*winner_node;

	winner_node = NULL;
	if (init(&sta, a, b))
		return (free_stack(sta), NULL);
	winner_node = loop(sta, pi, a, b);
	return (winner_node);
}

void	class_b(t_stack **a, t_stack **b, int *pi)
{
	t_stack	*clever;

	clever = NULL;
	if (*a == NULL || *b == NULL)
		return ;
	else
		clever = clever_chosing(a, b, pi);
	if (clever == NULL)
		return ;
	do_a(a, clever, pi, b);
	do_b(*a, b, pi);
	push_b(a, b, 1);
	(*pi)--;
	free_stack(clever);
}
