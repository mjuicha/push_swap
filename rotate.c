/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:09:22 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/22 15:27:50 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*head;
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = (*a)->next;
	temp = *a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *a;
	(*a)->next = NULL;
	*a = head;
}

void	rot_a(t_stack **a, int i)
{
	rotate(a);
	if (i)
		write(1, "ra\n", 3);
}

void	rot_b(t_stack **b, int i)
{
	rotate(b);
	if (i)
		write(1, "rb\n", 3);
}

void	rot_r(t_stack **a, t_stack **b, int i)
{
	rotate(a);
	rotate(b);
	if (i)
		write(1, "rr\n", 3);
}
