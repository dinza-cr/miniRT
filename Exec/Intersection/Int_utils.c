/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:37:34 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 14:52:22 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	count_shapes(t_shape *s)
{
	int			res;
	t_shape		*temp;

	res = 0;
	temp = s;
	while (temp)
	{
		res++;
		temp = temp->next;
	}
	return (res);
}

void	swap_i(t_intersection *a, t_intersection *b)
{
	t_intersection	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_intersections(t_intersections *xs)
{
	int	i;
	int	j;

	if (xs->count <= 1)
		return ;
	i = 0;
	while (i < xs->count - 1)
	{
		j = 0;
		while (j < xs->count - 1 - i)
		{
			if (xs->solutions[j].t > xs->solutions[j + 1].t)
				swap_i(&xs->solutions[j], &xs->solutions[j + 1]);
			j++;
		}
		i++;
	}
}

double	discriminant(t_ray r, double *a, double *b)
{
	double	res;
	double	c;
	t_tuple	sphere_to_ray;

	sphere_to_ray = top_subs(r.origin, cons_point(0, 0, 0));
	*a = top_dot(r.direction, r.direction);
	*b = 2.0 * top_dot(r.direction, sphere_to_ray);
	c = top_dot(sphere_to_ray, sphere_to_ray) - 1.0;
	res = ((*b) * (*b)) - (4.0 * (*a) * (c));
	return (res);
}
