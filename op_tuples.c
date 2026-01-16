/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:14:18 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/15 19:22:48 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	top_compare(t_tuple a, t_tuple b)
{
	if (fabs(a.x - b.x) <= EPSILON
		&& fabs(a.y - b.y) <= EPSILON
		&& fabs(a.z - b.z) <= EPSILON
		&& fabs(a.w - b.w) <= EPSILON)
		return (1);
	else
		return (0);
}

t_tuple	top_add(t_tuple a, t_tuple b)
{
	t_tuple	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	res.w = a.w + b.w; // if w == 2, error
	return (res);
}

t_tuple	top_subs(t_tuple a, t_tuple b)
{
	t_tuple	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.w = a.w - b.w; // if w < 0, error
	return (res);
}

t_tuple	top_negate(t_tuple a)
{
	t_tuple	res;

	res.x = 0.0 - a.x;
	res.y = 0.0 - a.y;
	res.z = 0.0 - a.z;
	res.w = 0.0 - a.w; // if w == -1, error
	return (res);
}

t_tuple	top_multi(t_tuple a, double scal)
{
	t_tuple	res;

	res.x = a.x * scal;
	res.y = a.y * scal;
	res.z = a.z * scal;
	res.w = a.w * scal;
	return (res);
}

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

	magn = top_magnitude(a); // if magn == 0, error
	res.x = a.x / magn;
	res.y = a.y / magn;
	res.z = a.z / magn;
	res.w = a.w / magn;
	return (res);
}

double top_dot(t_tuple a, t_tuple b)
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
