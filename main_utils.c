/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:18:54 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/01 16:20:54 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	simple_check(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' '))
		i++;
	if (!s[i])
		return (0);
	i = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+')
			&& ((s[i + 1] == '\0' || s[i + 1] == ' ' || s[i + 1] == '-'
					|| s[i + 1] == '+')
				|| (s[i - 1] >= '0' && s[i - 1] <= '9')))
			return (0);
		if (s[i] != ' ' && (s[i] < '0' || s[i] > '9')
			&& !(s[i] == '+' || s[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

//check if the arguments are valid and return them in a 2d array
char	**ft_check_args(char **av)
{
	int		i;
	char	*ret;

	i = 1;
	ret = ft_strdup("");
	while (av[i])
	{
		if (simple_check(av[i]) == 0)
			ft_error();
		ret = ft_strjoin(ret, av[i]);
		ret = ft_strjoin(ret, " ");
		i++;
	}
	return (ft_split(ret, ' '));
}

//check if there are duplicates in the stack
void	check_duplicate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				push_swap_error(stack);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

//fill the stack with the arguments
void	fill_stack(t_stack **stack, char **av)
{
	int			i;
	long int	res;

	i = 0;
	while (av[i])
	{
		res = ft_atoi(av[i]);
		if (res > INT_MAX || res < INT_MIN)
			push_swap_error(stack);
		ft_lstadd_back(stack, ft_lstnew(res));
		i++;
	}
	check_duplicate(stack);
}
