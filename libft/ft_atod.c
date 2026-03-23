/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:37:17 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/23 14:33:28 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <float.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\n' || c == '\f');
}

long double	atod_ent(char *str, int *i)
{
	long double	res;

	res = 0.0;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		res = res * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (res);
}

long double	atod_frac(char *str, int *i)
{
	long double	frac;
	long double	div;

	frac = 0.0;
	div = 1.0;
	if (str[*i] == '.')
		(*i)++;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		frac = frac * 10.0 + (str[*i] - '0');
		div *= 10.0;
		(*i)++;
	}
	return (frac / div);
}

double	ft_atod(char *str)
{
	long double	res;
	long double	frac;
	int			sign;
	int			i;

	if (!str)
		return (0.0);
	i = 0;
	sign = 1;
	frac = 0.0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	res = atod_ent(str, &i);
	frac = atod_frac(str, &i);
	res = res + frac;
	return ((double)(sign * res));
}
