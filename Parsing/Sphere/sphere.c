/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:20:21 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 18:58:37 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//constructeur
t_sphere	cons_sphere(void)
{
	t_sphere	res;

	res.valid = 0;
	res.coord = cons_point(0, 0, 0);
	res.diameter = 0;
	res.radius = 0;
	return (res);
}

t_shape	*pars_sphere(char **info)
{
	t_shape *res;

	res = cons_shape();
	if (!res)
		return (NULL);
	if (count_elem(info) != 4)
		return (res);
	res->sphere.coord = get_point(info[1]);
	if (res->sphere.coord.w == -1)
		return (res);
	res->sphere.diameter = ft_atod(info[2]);
	if (res->sphere.diameter <= 0.0)
		return (res);
	res->sphere.radius = res->sphere.diameter / 2;
	res->material.color = get_color(info[3]);
	if (res->material.color.r == -1)
		return (res);
	res->transformation = sp_transform(res);
	res->inv_transfo = mop_inverse(res->transformation);
	res->sphere.valid = 1;
	return (res);
}

void	add_sphere(char **info, t_world *world)
{
	t_shape *new;

	new = pars_sphere(info);
	if (!new)
		return ;
	new->next = world->shapes;
	world->shapes = new;
}

t_matrix	sp_transform(t_shape *s)
{
	t_matrix	res;
	t_matrix	scaling;
	t_matrix	translation;

	res = cons_idmatrix();
	scaling = trsf_scaling(s->sphere.radius, s->sphere.radius, s->sphere.radius);
	translation = trsf_translation(s->sphere.coord.x, s->sphere.coord.y, s->sphere.coord.z);
	res = mop_multimat(translation, scaling);
	return (res);
}

void	set_transform(t_shape *s, t_matrix t)
{
	s->transformation = mop_copy(t);
	s->inv_transfo = mop_inverse(t);
}
