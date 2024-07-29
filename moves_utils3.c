/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:36:27 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/29 19:45:29 by mjuicha          ###   ########.fr       */
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

void	pa(t_stack **a, t_stack **b)
{
	if (push(b, a) == 0)
	    write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(a, b) == 0)
	    write(1, "pb\n", 3);
}
