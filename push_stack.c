/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:41:06 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/23 17:16:23 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*push_stack(t_stack **a, char *av)
{
	t_stack	*new;
	t_stack	*temp;

	new = create_node(ft_atoi(av));
	if (*a == NULL)
		*a = new;
	else
	{
		temp = *a;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	return (new);
}

void	print(t_stack *a)
{
	while (a != NULL)
	{
		printf("%d->", a->value);
		a = a->next;
	}
	write(1, "\n", 1);
}
