/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:18:06 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 19:23:06 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index == 0)
			break ;
		else if (ft_lstlast(*stack_a)->index == 0)
			r_rot_a(stack_a, 1);
		else
			rot_a(stack_a, 1);
		tmp = *stack_a;
	}
	push_b(stack_a, stack_b, 1);
	if (check_asc(stack_a))
		sort_three(stack_a);
	push_a(stack_a, stack_b, 1);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index == 1)
			break ;
		else if (ft_lstlast(*stack_a)->index == 1)
			r_rot_a(stack_a, 1);
		else
			rot_a(stack_a, 1);
		tmp = *stack_a;
	}
	push_b(stack_a, stack_b, 1);
	sort_4(stack_a, stack_b);
	push_a(stack_a, stack_b, 1);
	swap_a(stack_a, 1);
}

int	get_index(t_stack *tmp, int value)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (tmp->value < value)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	indexing_stack(t_stack *to_stack)
{
	t_stack	*tmp;

	tmp = to_stack;
	while (tmp)
	{
		tmp->index = get_index(to_stack, tmp->value);
		tmp = tmp->next;
	}
}

void	spec(t_stack **sta, t_stack **stb)
{
	indexing_stack(*sta);
	if (count_stack(sta) == 4)
		sort_4(sta, stb);
	else
		sort_5(sta, stb);
}
