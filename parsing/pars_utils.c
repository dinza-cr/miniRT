/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:35:03 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/24 14:53:12 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	count_elem(char **t)
{
	int i = 0;
	
	while (t && t[i])
		i++;
	return (i);
}

void	free_split(char **t)
{
	int i;
	
	if (!t)
		return;
	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
}

int	in_range(double x, double a, double b)
{
	return (x >= a && x <= b);
}