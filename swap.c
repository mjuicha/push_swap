/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:08:27 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 16:33:43 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*temp;
	t_stack	*head;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	head = (*a)->next;
	temp = *a;
	temp->next = head->next;
	head->next = temp;
	*a = head;
}

void	swap_a(t_stack **a, int i)
{
	swap(a);
	if (i)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **b, int i)
{
	swap(b);
	if (i)
		write(1, "sb\n", 3);
}

void	swap_s(t_stack **a, t_stack **b, int i)
{
	swap(a);
	swap(b);
	if (i)
		write(1, "ss\n", 3);
}
