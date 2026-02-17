/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:26:24 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 19:10:45 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//constructeur
t_ray	cons_ray(t_tuple origin, t_tuple direction)
{
	t_ray res;

	res.origin = origin;
	res.direction = direction;
	return (res);
}

//fonctions
t_tuple	position(t_ray r, float t)
{
	t_tuple	res;
	t_tuple	distance;
	
	distance = top_multi(r.direction, t);
	res = top_add(r.origin, distance);
	return (res);
}


