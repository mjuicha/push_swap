/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:02:03 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/19 17:02:38 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack(t_stack	**sta)
{
	t_stack	*temp;
	int		count;

	if (*sta == NULL || sta == NULL)
		return (0);
	count = 1;
	temp = *sta;
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	check_asc(t_stack **sta)
{
	t_stack	*temp;

	if (*sta == NULL || sta == NULL)
		return (1);
	temp = *sta;
	while (temp->next != NULL)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}

t_stack	*min(t_stack **a)
{
	t_stack	*temp;
	t_stack	*min;

	if (*a == NULL || a == NULL)
		return (NULL);
	temp = *a;
	min = temp;
	while (temp != NULL)
	{
		if (min->value > temp->value)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_stack	*max(t_stack **a)
{
	t_stack	*temp;
	t_stack	*max;

	if (*a == NULL || a == NULL)
		return (NULL);
	temp = *a;
	max = temp;
	while (temp != NULL)
	{
		if (max->value < temp->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}
