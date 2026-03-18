/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:54:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 14:32:00 by dinza-cr         ###   ########.fr       */
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

t_color	cop_shade_hit(t_world *world, t_comps comps)
{
	t_color	res;
	int		in_shadow;

	in_shadow = is_shadowed(world, comps.overpoint);
	res = lighting(comps.shape->material, world->L, comps.overpoint,
			comps.eyev, comps.normalv, in_shadow);
	return (res);
}

t_color	color_at(t_world *world, t_ray r)
{
	t_comps			comps;
	t_intersections	xs;
	double			hit;
	int				i;
	t_color			color;

	xs = iop_intersect_world(world, r);
	hit = iop_hit(xs);
	if (xs.count <= 0 || !xs.solutions || hit == INFINITY)
		return (dest_intersections(&xs), cons_color(0, 0, 0));
	i = 0;
	while (i < xs.count)
	{
		if (hit == xs.solutions[i].t)
		{
			comps = cons_comps(xs.solutions[i], r);
			break ;
		}
		i++;
	}
	if (comps.valid != 1)
		return (dest_intersections(&xs), cons_color(0, 0, 0));
	color = cop_shade_hit(world, comps);
	dest_intersections(&xs);
	return (color);
}
