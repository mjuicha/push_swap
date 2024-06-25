/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:41:08 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/25 17:44:03 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2)
		return (1);
	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (j == 0 && (av[i][0] == '+' || av[i][0] == '-'))
				j++;
			if (!ft_isdigit(av[i][j]))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_rep(t_stack *a, t_stack *b)
{
	if (b == NULL)
		return (0);
	while (b != NULL && a != NULL)
	{
		if (a->value == b->value)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		b = b->prev;
	}
	return (0);
}

void	pusher(t_stack **a, char *av, int *pt)
{
	t_stack	*stack_a;
	t_stack	*stack_r;
	int		c;

	stack_a = *a;
	c = *pt;
	stack_r = NULL;
	stack_r = push_stack(&stack_a, av);
	check_over(stack_r->value, &c);
	c = check_rep(stack_r, stack_r->prev);
	*pt = c;
	*a = stack_a;
}

void	check_over(long long int i, int *pt)
{
	if (i > INT_MAX || i < INT_MIN)
		(*pt) = 1;
}
