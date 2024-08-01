/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:59:11 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/01 21:48:07 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d_array(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	l()
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		c;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	c = 0;
	av = ft_check_args(av);
	fill_stack(&stack_a, av);
	algorithem(&stack_a, &stack_b);
	free_2d_array(av);
	free_stack(stack_a);
	free_stack(stack_b);
	atexit(l);
	return (0);
}
