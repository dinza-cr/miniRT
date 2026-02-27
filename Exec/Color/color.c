/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:54:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 13:05:44 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//constructeur
t_color	cons_color(double r, double g, double b)
{
	t_color	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

t_color cop_shade_hit(t_world *world, t_comps comps) // a terminer (bonus multiple spotlight)
{
	t_color res;
		
	res = lighting(comps.s->m, world->L, comps.point, comps.eyev, comps.normalv);
	return (res);
}

t_color color_at(t_world *world, t_ray r)
{
	t_comps comps;
	t_intersections xs = iop_intersect_world(world, r);
	double hit = iop_hit(xs);
	if (!xs.count)
		return (cons_color(0, 0, 0));
	else
	{
		for (int i = 0; i < xs.count; i++)
		{
			if (hit == xs.solutions[i].t)
			{
				comps = cons_comps(xs.solutions[i], r);
				break ;
			}
		}
		t_color color = cop_shade_hit(world, comps);
		return (color);
	}
}
