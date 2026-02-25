/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:20:21 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/25 19:12:13 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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

t_matrix sp_transform(t_sphere *s)
{
	t_matrix res;
	t_matrix scaling;
	t_matrix translation;

	res = cons_idmatrix();
	scaling = trsf_scaling(s->radius, s->radius, s->radius);
	translation = trsf_translation(s->coord.x, s->coord.y,s->coord.z);
	res = mop_multimat(translation, scaling);
	return (res);
}

t_sphere	*pars_sphere(char **info)
{
	t_sphere	*res;
	char		**buff;

	res = cons_sphere();
	if (!res)
		return (NULL);
	if (count_elem(info) != 4)
		return (res);
	buff = ft_split(info[1], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res->coord = cons_point(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	res->diameter = ft_atod(info[2]);
	if (res->diameter <= 0.0)
		return (res);
	res->radius = res->diameter/2;
	buff = ft_split(info[3], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res->m.color = cons_color(ft_atod(buff[0]) / 255.0, ft_atod(buff[1]) / 255.0, ft_atod(buff[2]) / 255.0);
	free_split(buff);
	if (!in_range(res->m.color.r, 0.0, 1.0) || !in_range(res->m.color.g, 0.0, 1.0) || !in_range(res->m.color.b, 0.0, 1.0))
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

void	set_transform(t_sphere *s, t_matrix t)
{
	s->transform = mop_copy(t);
}
