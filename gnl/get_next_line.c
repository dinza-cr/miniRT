/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:25:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/22 16:02:09 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add(char *stash, char *buff)
{
	char	*newstash;

	newstash = ft_join(stash, buff);
	if (!newstash)
		return (NULL);
	free(stash);
	return (newstash);
}

char	*ft_readf(int fd, char *stash)
{
	char	*buff;
	int		bytes;

	bytes = 1;
	if (!stash)
		stash = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buff || !stash)
		return (NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buff), free(stash), NULL);
		buff[bytes] = '\0';
		stash = ft_add(stash, buff);
		if (!stash)
			return (free(buff), free(stash), NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buff);
	return (stash);
}

char	*ft_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (stash[i] == '\0')
		return (NULL);
	while ((stash[i]) && (stash[i] != '\n'))
		i++;
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while ((stash[i]) && (stash[i] != '\n'))
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && (stash[i] == '\n'))
		line[i] = '\n';
	return (line);
}

char	*ft_save(char *stash)
{
	char	*newstash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && (stash[i] != '\n'))
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	newstash = ft_calloc((ft_strlen(stash) - i + 1), 1);
	if (!newstash)
		return (free(stash), NULL);
	i++;
	while (stash[i + j])
	{
		newstash[j] = stash[i + j];
		j++;
	}
	free(stash);
	return (newstash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (read(fd, 0, 0) < 0))
		return (free(stash), stash = NULL, NULL);
	stash = ft_readf(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_save(stash);
	return (line);
}
