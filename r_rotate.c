/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:09:04 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/22 15:27:55 by mjuicha          ###   ########.fr       */
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

void	r_rot_a(t_stack **a, int i)
{
	r_rotate(a);
	if (i)
		write(1, "rra\n", 4);
}

void	r_rot_b(t_stack **b, int i)
{
	r_rotate(b);
	if (i)
		write(1, "rrb\n", 4);
}

void	r_rot_r(t_stack **a, t_stack **b, int i)
{
	r_rot_a(a, 0);
	r_rot_b(b, 0);
	if (i)
		write(1, "rrr\n", 4);
}
