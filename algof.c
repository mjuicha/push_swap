/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algof.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:04:10 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/24 18:19:17 by mjuicha          ###   ########.fr       */
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

void	logic(t_stack **a, t_stack **b)
{
	t_stack	*sta;
	t_stack	*stb;
	int		c;

	sta = *a;
	stb = *b;
	c = count_stack(&sta);
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
	if (stb == NULL)
		return ;
	if (check_asc(&sta) == 1)
	{
		printf("error");
		return ;
	}
	else
		class_a(&sta, &stb);
	if (check_asc(&sta))
		asc(&sta);
	*a = sta;
	*b = NULL;
}
