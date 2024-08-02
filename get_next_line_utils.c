/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <mjuicha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:50:27 by mjuicha           #+#    #+#             */
/*   Updated: 2024/08/02 16:50:21 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*empty_str(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	x;

	x = 0;
	while (str[x] != (char)c)
	{
		if (str[x] == '\0')
			return (0);
		x++;
	}
	return ((char *)&str[x]);
}
