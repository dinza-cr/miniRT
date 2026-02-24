/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:21:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/24 14:27:30 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//constructor
t_world	*cons_world(void)
{
	t_world	*res;

	res = malloc(sizeof(t_world));
	if (!res)
		return (NULL);
	res->valid = 0;
	res->has_ambient = 0;
	res->has_camera = 0;
	res->has_light = 0;
	res->spheres = NULL;
	res->planes = NULL;
	res->cylinders = NULL;
	return (res);
}

//destructor
void	dest_world(t_world *world)
{
	if (!world)
		return ;
	dest_spheres(world->spheres);
	dest_planes(world->planes);
	dest_cylinders(world->cylinders);
	free(world);
}

t_world *default_world(void)
{
	t_world *res;

	res = cons_world();
	res->L = point_light(cons_point(-10, 10, -10), cons_color(1, 1, 1));
	res->spheres = init_sphere();
	res->spheres->m.color = cons_color(0.8, 1.0, 0.6);
	res->spheres->m.ambient = 0.7;
	res->spheres->m.specular = 0.2;
	res->spheres->next = init_sphere();
	res->spheres->next->transform = trsf_scaling(0.5, 0.5, 0.5);
	return (res);
}