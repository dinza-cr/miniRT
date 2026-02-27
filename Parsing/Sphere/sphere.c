/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:20:21 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 18:26:55 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//constructeur
t_sphere	*cons_sphere(void)
{
	t_sphere	*res;

	res = malloc(sizeof(t_sphere));
	if (!res)
		return (NULL);
	res->valid = 0;
	res->coord = cons_point(0, 0, 0);
	res->diameter = 0;
	res->radius = 0;
	res->m.color = cons_color(0, 0, 0);
	res->transform = cons_idmatrix();
	res->m = init_material();
	res->next = NULL;
	return (res);
}

//destructeur
void	dest_spheres(t_sphere *sp)
{
	t_sphere	*tmp;

	while (sp)
	{
		tmp = sp->next;
		free(sp);
		sp = tmp;
	}
}

t_sphere	*pars_sphere(char **info)
{
	t_sphere	*res;

	res = cons_sphere();
	if (!res)
		return (NULL);
	if (count_elem(info) != 4)
		return (res);
	res->coord = get_point(info[1]);
	if (res->coord.w == -1)
		return (res);
	res->diameter = ft_atod(info[2]);
	if (res->diameter <= 0.0)
		return (res);
	res->radius = res->diameter / 2;
	res->m.color = get_color(info[3]);
	if (res->m.color.r == -1)
		return (res);
	res->transform = sp_transform(res);
	res->valid = 1;
	return (res);
}

void	add_sphere(char **info, t_world *world)
{
	t_sphere	*new;

	new = pars_sphere(info);
	if (!new)
		return ;
	new->next = world->spheres;
	world->spheres = new;
}

t_matrix	sp_transform(t_sphere *s)
{
	t_matrix	res;
	t_matrix	scaling;
	t_matrix	translation;

	res = cons_idmatrix();
	scaling = trsf_scaling(s->radius, s->radius, s->radius);
	translation = trsf_translation(s->coord.x, s->coord.y,s->coord.z);
	res = mop_multimat(translation, scaling);
	return (res);
}

void	set_transform(t_sphere *s, t_matrix t)
{
	s->transform = mop_copy(t);
}
