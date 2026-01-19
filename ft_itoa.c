/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:00:57 by anbelose          #+#    #+#             */
/*   Updated: 2026/01/18 18:43:10 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_len(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	fill_res(long nb, char *res, int *i)
{
	if (nb >= 10)
	{
		fill_res(nb / 10, res, i);
	}
	res[*i] = (nb % 10) + '0';
	(*i)++;
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*res;
	int		i;

	nb = (long)n;
	i = 0;
	res = (char *)malloc(sizeof(char) * (count_len(nb) + 1));
	if (!res)
		return (NULL);
	if (nb < 0)
	{
		res[i] = '-';
		i++;
		nb *= -1;
	}
	fill_res(nb, res, &i);
	res[i] = '\0';
	return (res);
}
