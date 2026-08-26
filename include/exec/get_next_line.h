/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:25:32 by dinza-cr          #+#    #+#             */
/*   Updated: 2025/06/08 17:41:38 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_strchr(const char *s, int c);
char	*ft_join(char *stash, char *buff);
char	*ft_add(char *stash, char *buff);
char	*ft_readf(int fd, char *stash);
char	*ft_line(char *stash);
char	*ft_save(char *stash);
char	*gnl_calloc(int n, int size);
int		gnl_strlen(char *str);

#endif