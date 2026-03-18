/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tuples2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:58:55 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 15:59:41 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_tuple	top_divi(t_tuple a, double scal)
{
	t_tuple	res;

	res.x = a.x / scal;
	res.y = a.y / scal;
	res.z = a.z / scal;
	res.w = a.w / scal;
	return (res);
}

double	top_magnitude(t_tuple a)
{
	double	res;

	res = sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
	return (res);
}

t_tuple	top_normalize(t_tuple a)
{
	t_tuple	res;
	double	magn;

	magn = top_magnitude(a);
	res.x = a.x / magn;
	res.y = a.y / magn;
	res.z = a.z / magn;
	res.w = a.w / magn;
	return (res);
}

double	top_dot(t_tuple a, t_tuple b)
{
	double	res;

	res = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (res);
}

t_tuple	top_cross(t_tuple a, t_tuple b)
{
	t_tuple	res;

	res = cons_vector(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x);
	return (res);
}
