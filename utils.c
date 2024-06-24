/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:40:57 by mjuicha           #+#    #+#             */
/*   Updated: 2024/05/11 13:27:07 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*get_word(char *s, char c)
{
	char	*word;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	*ft_free(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**spl;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	spl = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (spl == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			spl[i++] = get_word(s, c);
			if (!spl[i - 1])
				return (ft_free(spl, i - 1));
			while (*s && *s != c)
				s++;
		}
	}
	spl[i] = NULL;
	return (spl);
}
