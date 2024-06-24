/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 01:59:45 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/23 08:44:38 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cheap_min(int c, t_stack **a)
{
	t_stack	*sec;
	t_stack	*look;

	look = *a;
	sec = NULL;
	while (sec == NULL && look != NULL)
	{
		if (c < look->value)
			sec = look;
		look = look->next;
	}
	while (look != NULL)
	{
		if (c < look->value && look->value < sec->value)
			sec = look;
		look = look->next;
	}
	if (sec == NULL)
		sec = min(a);
	return (sec);
}

void	clever_class(t_stack **a, t_stack **b)
{
	t_stack	*sec;
	int		size_a;

	give_index(a);
	give_index(b);
	size_a = count_stack(a);
	sec = cheap_min((*b)->value, a);
	if (sec == NULL)
		return ;
	while (*b != NULL && sec->value != (*a)->value)
	{
		if (sec == NULL)
			break ;
		else if (sec->index <= size_a / 2)
			rot_a(a, 1);
		else if (sec->index > size_a / 2)
			r_rot_a(a, 1);
	}
	push_a(a, b, 1);
}

void	class_a(t_stack **a, t_stack **b)
{
	if (*a == NULL || *b == NULL)
		return ;
	while (*b != NULL)
		clever_class(a, b);
}

void	asc(t_stack **a)
{
	t_stack	*sec;
	int		i;
	int		count;

	give_index(a);
	count = count_stack(a);
	sec = min(a);
	if (sec->index > count / 2)
		i = 1;
	else if (sec->index <= count / 2)
		i = 2;
	while ((*a)->value != sec->value)
	{
		if (i == 1)
			r_rot_a(a, 1);
		if (i == 2)
			rot_a(a, 1);
	}
}
