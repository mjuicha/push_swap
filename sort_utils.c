/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:44:09 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/29 19:50:30 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min(t_stack **stack)
{
    t_stack	*tmp;
    t_stack	*min;

    tmp = *stack;
    min = tmp;
    while (tmp)
    {
        if (tmp->value < min->value)
            min = tmp;
        tmp = tmp->next;
    }
    return (min);
}

t_stack	*max(t_stack **stack)
{
    t_stack	*tmp;
    t_stack	*max;

    tmp = *stack;
    max = tmp;
    while (tmp)
    {
        if (tmp->value > max->value)
            max = tmp;
        tmp = tmp->next;
    }
    return (max);
}

int get_index(t_stack *tmp, int value)
{
    int		i;

    i = 0;
    while (tmp)
    {
        if (tmp->value < value)
            i++;
        tmp = tmp->next;
    }
    return (i);
}

void    indexing_stack(t_stack *to_stack)
{
    t_stack	*tmp;

    tmp = to_stack;
    while (tmp)
    {
        tmp->index = get_index(to_stack, tmp->value);
        tmp = tmp->next;
    }
}
