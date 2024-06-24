/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:24:07 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/23 18:13:42 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr1(t_stack **sta, t_stack **a, t_stack **b, int *pt)
{
	t_stack	*temp;

	temp = br(*a, *b);
	*b = temp;
	r_rot_r(sta, b, 1);
	(*pt)--;
}

void	rr1(t_stack **sta, t_stack **a, t_stack **b, int *pt)
{
	t_stack	*temp;

	temp = br1(*a, *b);
	*b = temp;
	rot_r(sta, b, 1);
	(*pt)--;
}
/* ************************************************************************** */

void	rrr0(t_stack **sta, t_stack **a, t_stack **b, int *pt)
{
	t_stack	*temp;

	temp = br(*a, *b);
	*b = temp;
	r_rot_r(sta, b, 0);
	(*pt)--;
}

void	rr0(t_stack **sta, t_stack **a, t_stack **b, int *pt)
{
	t_stack	*temp;

	temp = br1(*a, *b);
	*b = temp;
	rot_r(sta, b, 0);
	(*pt)--;
}
