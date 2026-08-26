/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:33:14 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 15:09:43 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//constructeur
t_intersection	cons_intersection(double t, t_shape *object)
{
	t_intersection	res;

	res.t = t;
	res.object = object;
	return (res);
}

double	iop_hit(t_intersections xs)
{
	double	best;
	int		i;

	if (xs.count <= 0 || xs.solutions == NULL)
		return (INFINITY);
	best = INFINITY;
	i = 0;
	while (i < xs.count)
	{
		if (xs.solutions[i].t >= 0 && xs.solutions[i].t < best)
			best = xs.solutions[i].t;
		i++;
	}
	return (best);
}
