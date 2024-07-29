/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:38:54 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/29 19:46:15 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *a;
	*a = last;
}

void	rra(t_stack **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rrr\n", 4);
}
