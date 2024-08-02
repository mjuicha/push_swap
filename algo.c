/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:04:10 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 15:26:12 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if (min(a) == *a)
	{
		r_rot_a(a, 1);
		swap_a(a, 1);
	}
	else if (max(a) == *a)
	{
		rot_a(a, 1);
		if (check_asc(a) != 0)
			swap_a(a, 1);
	}
	else
	{
		if (min(a) == (*a)->next)
			swap_a(a, 1);
		else
			r_rot_a(a, 1);
	}
}

void	first_push(t_stack **sta, t_stack **stb, int *pi)
{
	int	c;

	c = *pi;
	if (c == 4)
	{
		push_b(sta, stb, 1);
		c = c - 1;
	}
	else
	{
		push_b(sta, stb, 1);
		push_b(sta, stb, 1);
		c -= 2;
	}
	*pi = c;
}

void	less_3(t_stack **sta)
{
	if (count_stack(sta) == 3 && check_asc(sta) != 0)
		sort_three(sta);
	if (count_stack(sta) == 2 && check_asc(sta) != 0)
		swap_a(sta, 1);
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

void    sort_5(t_stack **stack_a, t_stack **stack_b)
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

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("value: %d index: %d\n", tmp->value, tmp->index);
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
	// print_stack(*sta);
}

void	logic(t_stack **a, t_stack **b)
{
	t_stack	*sta;
	t_stack	*stb;
	int		c;

	sta = *a;
	stb = *b;
	c = count_stack(&sta);
	if ( c == 4 || c == 5)
	{
		spec(&sta, &stb);
		*a = sta;
		*b = stb;
		return ;
	}
	if (c > 3 && stb == NULL)
		first_push(&sta, &stb, &c);
	while (count_stack(&sta) > 3)
		class_b(&sta, &stb, &c);
	if (count_stack(&sta) <= 3)
		less_3(&sta);
	*a = sta;
	*b = stb;
}

void	algorithem(t_stack **a, t_stack **b)
{
	t_stack	*sta;
	t_stack	*stb;

	sta = *a;
	stb = *b;
	if (sta == NULL)
		return ;
	if (check_asc(&sta) == 0)
		return ;
	logic(&sta, &stb);
	class_a(&sta, &stb);
	if (check_asc(&sta))
		asc(&sta);
	*a = sta;
	*b = NULL;
}
