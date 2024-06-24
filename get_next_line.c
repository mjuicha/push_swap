/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuicha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:44:21 by mjuicha           #+#    #+#             */
/*   Updated: 2024/06/18 17:16:31 by mjuicha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	if (!str)
		str = empty_str();
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (str);
}

char	*the_line(char *str)
{
	char	*save;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	save = (char *)malloc(sizeof(char) * (i + 1));
	if (!save)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		save[i] = str[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	*next_line(char *str)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	next = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!next)
		return (0);
	i++;
	while (str[i])
		next[j++] = str[i++];
	next[j] = '\0';
	free(str);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		return (0);
	}
	str = read_line(fd, str);
	if (!str)
		return (0);
	line = the_line(str);
	str = next_line(str);
	return (line);
}
