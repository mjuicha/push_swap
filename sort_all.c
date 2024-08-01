/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 03:06:25 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/25 03:33:33 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstlast(t_stack **lst)
{
    t_stack    *tmp;

    tmp = *lst;
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp);
}

void    sort_all(t_stack **a, t_stack **b)
{
    t_stack    *m;

    while (*a != NULL)
    {
        m = min(a);
        while (*a != m)
        {
            if ((*a)->index <= count_stack(a) / 2)
                rot_a(a, 1);
            else
                r_rot_a(a, 1);
        }
        push_b(a, b, 1);
    }
    while (*b != NULL)
        push_a(a, b, 1);
}