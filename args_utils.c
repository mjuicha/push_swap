/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:39:07 by mjuicha           #+#    #+#             */
/*   Updated: 2024/07/28 11:36:52 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	isoverflow(long long int check, long long int res)
{
	if (res / 10 == check)
		return (0);
	return (1);
}

int	is_sspace( char *str, int *pt)
{
	int	i;
	int	retsi;

	i = 0;
	retsi = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			retsi *= -1;
		i++;
	}
	*pt = i;
	return (retsi);
}

int	ft_atoi(char *str, t_stack **stack)
{
	long long int	r;
	int				s;
	long long int	check;
	int				i;
	int				l;

	r = 0;
	l = 0;
	s = is_sspace(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = r;
		r = r * 10 + (str[i] - '0');
		if (isoverflow(check, r) == 1)
		{
			if (s == -1)
				return (0);
			return (-1);
		}
		i++;
		l++;
	}
	if (l > 10)
		push_swap_error(stack);
	return (r * s);
}
