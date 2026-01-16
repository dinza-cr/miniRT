/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:07:41 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/16 15:11:02 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *p;

    p = s;
    i = 0;
    while (i < n)
    {
        *p = (unsigned char)c;
        p++;
        i++;
    }
    return (s);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void *mem;
	if (size == 0)
		return (0);
	mem = malloc(nmemb * size);
	if (!mem)
		return (0);
	ft_memset(mem, 0, nmemb * size);
	return (mem);
}

int	ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}