/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:59:11 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/24 17:20:55 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		c;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	c = 0;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	if (check_input(ac, av) == 0)
	{
		while (av[i] != NULL && !c)
			pusher(&stack_a, av[i++], &c);
		if (!c)
			algorithem(&stack_a, &stack_b);
	}
	return (0);
}
