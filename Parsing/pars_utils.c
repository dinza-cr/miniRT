/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:35:03 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/24 11:07:27 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	count_elem(char **t)
{
	int	i;

	i = 0;
	while (t && t[i])
		i++;
	return (i);
}

void	free_split(char **t)
{
	int	i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
}

int	in_range(double x, double a, double b)
{
	return (x >= a && x <= b);
}

int	safe_exit(t_canva *canva, t_world *world)
{
	dest_canva(canva);
	dest_world(world);
	exit(0);
	return (0);
}
