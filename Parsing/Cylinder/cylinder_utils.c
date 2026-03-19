/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:51:17 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 16:51:28 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_cap(t_ray r, double t)
{
	double	x;
	double	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	return (((x * x) + (z * z)) <= 1);
}

int	cylinder_count_caps(t_shape *s, t_ray r)
{
	double	t;
	int		count;

	count = 0;
	if (fabs(r.direction.y) <= EPSILON)
		return (0);
	t = (s->cylinder.minimum - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		count++;
	t = (s->cylinder.maximum - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		count++;
	return (count);
}
