/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:14:00 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/20 12:14:29 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	doswap(char *s, t_stack **a, t_stack **b)
{
	if (strcmp(s, "sa") == 0)
		swap_a(a, 0);
	if (strcmp(s, "sb") == 0)
		swap_b(b, 0);
	if (strcmp(s, "ss") == 0)
		swap_s(a, b, 0);
}

void	dorot(char *s, t_stack **a, t_stack **b)
{
	if (strcmp(s, "ra") == 0)
		rot_a(a, 0);
	if (strcmp(s, "rb") == 0)
		rot_b(b, 0);
	if (strcmp(s, "rr") == 0)
		rot_r(a, b, 0);
}

void	dorrot(char *s, t_stack **a, t_stack **b)
{
	if (strcmp(s, "rra") == 0)
		r_rot_a(a, 0);
	if (strcmp(s, "rrb") == 0)
		r_rot_b(b, 0);
	if (strcmp(s, "rrr") == 0)
		r_rot_r(a, b, 0);
}

void	dopush(char *s, t_stack **a, t_stack **b)
{
	if (strcmp(s, "pa") == 0)
		push_a(a, b, 0);
	if (strcmp(s, "pb") == 0)
		push_b(a, b, 0);
}
