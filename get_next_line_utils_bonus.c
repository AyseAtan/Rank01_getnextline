/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatan <aatan@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:56:28 by aatan             #+#    #+#             */
/*   Updated: 2024/01/15 15:37:08 by aatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//#include <stdlib.h>
//#include <unistd.h>
//#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (destsize)
	{
		i = 0;
		while (i < (destsize - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

char	*ft_strdup(const char *str)
{
	char	*duplicate;
	size_t	i;

	i = 0;
	duplicate = malloc((ft_strlen(str) + 1) * sizeof(char *));
	if (!duplicate)
		return (NULL);
	while (str[i])
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	char	*result;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		result[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		result[i] = *s2++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(const char *str, int find)
{
	while (*str != '\0' && *str != (unsigned char) find)
		str++;
	if (*str == (unsigned char)find)
		return ((char *) str);
	return (0);
}
