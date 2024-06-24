/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:17:55 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/22 12:21:31 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
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
			xxxx(&stack_a, av[i++], &c);
		if (!c)
			my_algo(&stack_a, &stack_b);
	}
	return (0);
}
