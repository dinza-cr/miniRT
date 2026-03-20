/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:37:17 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/20 14:08:30 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\n' || c == '\f');
}

static int	ft_count(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '.')
		return (1);
	i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		i++;
	}
	return (res);
}

double	ft_atod(char *str)
{
	int		i;
	double	sign;
	double	res;
	int		vir;

	i = 0;
	sign = 1.0;
	res = 0.0;
	vir = ft_count(str);
	if (!str || !(*str))
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1.0;
	while (str[i] && ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
			res = res * 10 + (str[i++] - '0');
	}
	return (res * sign / (double)vir);
}
