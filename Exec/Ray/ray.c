/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:26:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 18:37:05 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//constructeur
t_ray	cons_ray(t_tuple origin, t_tuple direction)
{
	t_ray	res;

	res.origin = origin;
	res.direction = direction;
	return (res);
}

//fonctions
t_tuple	rop_position(t_ray r, float t)
{
	t_tuple	res;
	t_tuple	distance;

	distance = top_multi(r.direction, t);
	res = top_add(r.origin, distance);
	return (res);
}

t_ray	rop_transform(t_ray ray, t_matrix matrix)
{
	t_ray	res;

	res.origin = mop_multitup(matrix, ray.origin);
	res.direction = mop_multitup(matrix, ray.direction);
	return (res);
}
