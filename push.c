/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:08:52 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/16 18:12:56 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (a == NULL || *a == NULL)
		return (1);
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	return (0);
}

void	push_a(t_stack **a, t_stack **b, int i)
{
	if (push(b, a) == 0)
	{
		if (i)
			write(1, "pa\n", 3);
	}
}

void	push_b(t_stack **a, t_stack **b, int i)
{
	if (push(a, b) == 0)
	{
		if (i)
			write(1, "pb\n", 3);
	}
}
