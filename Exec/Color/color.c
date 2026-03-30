/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:54:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/30 19:41:24 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

#define MAX_REFLECTION_DEPTH 5

//constructeur
t_color	cons_color(double r, double g, double b)
{
	t_color	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

static t_color	color_at_limit(t_world *world, t_ray r, int remaining);

static t_color	reflected_color(t_world *world, t_comps comps, int remaining)
{
	t_ray	reflect_ray;
	t_tuple	reflectv;
	t_color	color;

	if (remaining <= 0 || comps.shape->material.reflective <= 0.0)
		return (cons_color(0, 0, 0));
	reflectv = reflect(top_negate(comps.eyev), comps.normalv);
	reflect_ray = cons_ray(comps.overpoint, reflectv);
	color = color_at_limit(world, reflect_ray, remaining - 1);
	return (cop_multi(color, comps.shape->material.reflective));
}

static t_color	cop_shade_hit_limit(t_world *world, t_comps comps, int remaining)
{
	t_color			res;
	t_color			reflected;
	int				in_shadow;
	t_material		material;

	in_shadow = is_shadowed(world, comps.overpoint);
	material = comps.shape->material;
	if (comps.shape->plane.valid)
		material.color = plane_texture_at(comps.shape, comps.point);
	res = lighting(material, world->L, comps.overpoint,
			comps.eyev, comps.normalv, in_shadow);
	reflected = reflected_color(world, comps, remaining);
	return (cop_add(res, reflected));
}

t_color cop_shade_hit(t_world *world, t_comps comps) // a terminer (bonus multiple spotlight)
{
	return (cop_shade_hit_limit(world, comps, MAX_REFLECTION_DEPTH));
}

static t_color	color_at_limit(t_world *world, t_ray r, int remaining)
{
	t_comps			comps;
	t_intersections	xs;
	double			hit;
	int				i;
	int				found;
	t_color			color;

	xs = iop_intersect_world(world, r);
	if (xs.count <= 0 || !xs.solutions)
		return (cons_color(0, 0, 0));
	hit = iop_hit(xs);
	if (hit == INFINITY)
	{
		dest_intersections(&xs);
		return (cons_color(0, 0, 0));
	}
	i = 0;
	found = 0;
	while (i < xs.count)
	{
		if (hit == xs.solutions[i].t)
		{
			comps = cons_comps(xs.solutions[i], r);
			found = 1;
			break ;
		}
		i++;
	}
	if (!found)
	{
		dest_intersections(&xs);
		return (cons_color(0, 0, 0));
	}
	color = cop_shade_hit_limit(world, comps, remaining);
	dest_intersections(&xs);
	return (color);
}

t_color	color_at(t_world *world, t_ray r)
{
	return (color_at_limit(world, r, MAX_REFLECTION_DEPTH));
}
