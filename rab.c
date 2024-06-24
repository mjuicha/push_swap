/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:41:50 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/20 18:31:13 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **sta, int *pt, int i)
{
	r_rot_a(sta, i);
	(*pt)--;
}

void	ra(t_stack **sta, int *pt, int i)
{
	rot_a(sta, i);
	(*pt)--;
}

void	rrb(t_stack **stb, int *pt, int i)
{
	r_rot_b(stb, i);
	(*pt)--;
}

void	rb(t_stack **stb, int *pt, int i)
{
	rot_b(stb, i);
	(*pt)--;
}
