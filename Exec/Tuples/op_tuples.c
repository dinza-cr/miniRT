/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tuples.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:14:18 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 15:59:51 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
	res.w = a.w + b.w;
	return (res);
}

t_tuple	top_subs(t_tuple a, t_tuple b)
{
	t_tuple	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	res.w = a.w - b.w;
	return (res);
}

t_tuple	top_negate(t_tuple a)
{
	t_tuple	res;

	res.x = 0.0 - a.x;
	res.y = 0.0 - a.y;
	res.z = 0.0 - a.z;
	res.w = 0.0 - a.w;
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
