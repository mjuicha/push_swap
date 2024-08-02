/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:54:37 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 18:26:38 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_index(t_stack **a)
{
	t_stack	*sta;
	int		i;

	if (a == NULL || *a == NULL)
		return ;
	sta = *a;
	i = 1;
	while (sta != NULL)
	{
		sta->index = i;
		i++;
		sta = sta->next;
	}
}

t_stack	*choosing(t_stack **a, int i)
{
	t_stack	*current;

	current = *a;
	while (current != NULL)
	{
		if (current->index == i)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_stack	*cheap_max(int c, t_stack **b)
{
	t_stack	*sec;
	t_stack	*look;

	look = *b;
	sec = NULL;
	while (sec == NULL && look != NULL)
	{
		if (c > look->value)
			sec = look;
		look = look->next;
	}
	while (look != NULL)
	{
		if (c > look->value && look->value > sec->value)
			sec = look;
		look = look->next;
	}
	if (sec == NULL)
		sec = max(b);
	return (sec);
}

t_stack	*copy_stack(t_stack *original)
{
	t_stack	*copy;

	if (original == NULL)
		return (NULL);
	copy = malloc(sizeof(t_stack));
	if (copy == NULL)
		return (NULL);
	copy->value = original->value;
	copy->index = original->index;
	copy->next = copy_stack(original->next);
	return (copy);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
