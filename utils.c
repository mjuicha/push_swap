/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:42:09 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 19:54:06 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * i + 1);
	if (!s)
		return (0);
	j = 0;
	while (j < i)
	{
		s[j] = s1[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup(""));
	len = ft_strlen(s1) + ft_strlen(s2);
	nstr = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		nstr[i] = s2[j];
		i++;
		j++;
	}
	nstr[i] = '\0';
	free((char *)s1);
	return (nstr);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	push_swap_error(t_stack **stack)
{
	free_stack(*stack);
	ft_error();
}
