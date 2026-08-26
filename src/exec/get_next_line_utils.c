/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:25:27 by dinza-cr          #+#    #+#             */
/*   Updated: 2025/06/10 16:48:53 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec/get_next_line.h"

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_join(char *stash, char *buff)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash || !buff)
		return (NULL);
	joined = malloc(gnl_strlen(stash) + gnl_strlen(buff) + 1);
	if (!joined)
		return (NULL);
	while (stash[i])
	{
		joined[i] = stash[i];
		i++;
	}
	while (buff[j])
	{
		joined[i + j] = buff[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

char	*gnl_calloc(int n, int size)
{
	char	*str;
	int		i;

	i = 0;
	if (n && size > 2147483647 / n)
		return (NULL);
	str = malloc (n * size);
	if (!str)
		return (NULL);
	while (i < n * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
