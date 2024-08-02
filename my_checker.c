/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:17:55 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 16:34:36 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void   l()
{
	system("leaks checker");
}
int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	av = ft_check_args(av);
	fill_stack(&stack_a, av);
	my_algo(&stack_a, &stack_b);
	free_2d_array(av);
	free_stack(stack_a);
	free_stack(stack_b);
	atexit(l);
	return (0);
}
