/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:33:14 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/16 18:20:25 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_intersection	cons_intersection()
{
	t_intersection res;

	res.t = 0.0;
	res.object = NULL;
	return (res);
}

t_intersection intersection(double t, t_sphere *object)
{
	t_intersection res;
	
	res.t = t;
	res.object = object;
	return (res);
}

t_intersect intersections(t_intersection i1, t_intersection i2)
{
	t_intersect res;

	res.xs[0] = i1;
	res.xs[1] = i2;
	res.count = 2;
	return (res);
}

double	hit(t_intersect xs)
{
	if(xs.xs[0].t < 0 && xs.xs[1].t < 0)
		return (0);
}
