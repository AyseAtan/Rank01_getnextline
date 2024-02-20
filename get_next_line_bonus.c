/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:56:40 by aatan             #+#    #+#             */
/*   Updated: 2024/01/15 15:59:28 by aatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include <stdlib.h>
//#include <unistd.h>
//#include <stddef.h>

static char	*make_store(int fd, char *store, char *buffer)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(store);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		if (!store)
			store = ft_strdup("");
		temp = store;
		store = ft_strjoin(store, buffer);
		free(temp);
	}
	free(buffer);
	return (store);
}

static char	*new_store(char *store)
{
	char	*new_store;
	int		i;

	i = 0;
	while (store[i] != '\n' && store[i])
		i++;
	if (store[i] == '\0')
	{
		free(store);
		return (NULL);
	}
	new_store = (char *) malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!new_store)
	{
		free(store);
		return (NULL);
	}
	ft_strlcpy(new_store, store + i + 1, ft_strlen(store) - i + 1);
	free(store);
	return (new_store);
}

static char	*extract_line(char *store)
{
	char	*line;
	int		i;

	i = 0;
	while (store[i] != '\n' && store[i])
		i++;
	line = malloc(sizeof(char *) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy (line, store, i + 2);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*store[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(store[fd]);
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[0] = '\0';
	if (!buffer)
	{
		free(store[fd]);
		return (NULL);
	}
	store[fd] = make_store(fd, store[fd], buffer);
	if (!store[fd])
		return (NULL);
	line = extract_line(store[fd]);
	store[fd] = new_store(store[fd]);
	return (line);
}
