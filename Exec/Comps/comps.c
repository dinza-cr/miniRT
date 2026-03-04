/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:06:10 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 15:54:07 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_comps	cons_comps(t_intersection i, t_ray r)
{
	t_comps	res;

	res.t = i.t;
	res.shape = i.object;
	res.point = rop_position(r, res.t);
	res.eyev = top_negate(r.direction);
	res.normalv = normal_at(res.shape, res.point);
	if (top_dot(res.normalv, res.eyev) < 0)
	{
		res.inside = 1;
		res.normalv = top_negate(res.normalv);
	}
	else
		res.inside = 0;
	res.overpoint = top_add(res.point, top_multi(res.normalv, EPSILON));
	return (res);
}