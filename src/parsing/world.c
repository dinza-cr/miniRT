/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:21:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/11 14:57:42 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//constructor
t_world	*cons_world(void)
{
	t_world	*res;

	res = malloc(sizeof(t_world));
	if (!res)
		return (NULL);
	res->shapes = NULL;
	res->valid = 0;
	res->has_ambient = 0;
	res->has_camera = 0;
	res->has_light = 0;
	res->A.valid = 0;
	res->C.valid = 0;
	res->L.valid = 0;
	return (res);
}

//destructor
void	dest_world(t_world *world)
{
	if (!world)
		return ;
	free(world);
}

t_world	*default_world(void)
{
	t_world	*res;

	res = cons_world();
	res->shapes = cons_shape();
	res->L = cons_light(cons_point(-10, 10, -10), cons_color(1, 1, 1));
	res->shapes->material.color = cons_color(0.8, 1.0, 0.6);
	res->shapes->material.diffuse = 0.7;
	res->shapes->material.specular = 0.2;
	res->shapes->sphere.valid = 1;
	res->shapes->next = cons_shape();
	res->shapes->next->sphere.valid = 1;
	res->shapes->next->transformation = trsf_scaling(0.5, 0.5, 0.5);
	res->shapes->next->inv_transfo = mop_inverse(trsf_scaling(0.5, 0.5, 0.5));
	return (res);
}