/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:23:25 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/29 19:49:59 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_2(t_stack **stack_a)
{
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void    sort_3(t_stack **stack_a)
{
    if (min(stack_a) == *stack_a)
    {
        rra(stack_a);
        sa(stack_a);
    }
    else if (max(stack_a) == *stack_a)
    {
        ra(stack_a);
        if (!check_sorted(*stack_a))
            sa(stack_a);
    }
    else
    {
        if (min(stack_a) == (*stack_a)->next)
            sa(stack_a);
        else
            rra(stack_a);
    }
}

void    sort_4(t_stack **stack_a, t_stack **stack_b)
{
    t_stack	*tmp;

    tmp = *stack_a;
    while (tmp)
    {
        if (tmp->index == 0)
            break ;
        else if (ft_lstlast(*stack_a)->index == 0)
            rra(stack_a);
        else
            ra(stack_a);
        tmp = *stack_a;
    }
    pb(stack_a, stack_b);
    if (!check_sorted(*stack_a))
        sort_3(stack_a);
    pa(stack_a, stack_b);
}

void    sort_5(t_stack **stack_a, t_stack **stack_b)
{
    t_stack	*tmp;

    tmp = *stack_a;
    while (tmp)
    {
        if (tmp->index == 1)
            break ;
        else if (ft_lstlast(*stack_a)->index == 1)
            rra(stack_a);
        else
            ra(stack_a);
        tmp = *stack_a;
    }
    pb(stack_a, stack_b);
    sort_4(stack_a, stack_b);
    pa(stack_a, stack_b);
    sa(stack_a);
}
    
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int	size;

    if (check_sorted(*stack_a))
        return ;
    size = ft_lstsize(*stack_a);
    if (size == 2)
        sort_2(stack_a);
    else if (size == 3)
        sort_3(stack_a);
    else if (size == 4)
        sort_4(stack_a, stack_b);
    else if (size == 5)
        sort_5(stack_a, stack_b);
    // else
    //     sort_big_stack(stack_a, stack_b);
}
