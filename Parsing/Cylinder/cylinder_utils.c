/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:51:17 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/20 15:41:58 by dinza-cr         ###   ########.fr       */
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

int	count_sides(t_shape *s, double *y)
{
	int	count;

	count = 0;
	if (y[0] > s->cylinder.minimum && y[0] < s->cylinder.maximum)
		count++;
	if (y[1] > s->cylinder.minimum && y[1] < s->cylinder.maximum)
		count++;
	return (count);
}

int	count_caps(t_shape *s, t_ray r)
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

void	cy_discriminant(double *disc, t_ray r, t_shape *s, t_intersection *t)
{
	disc[0] = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	disc[1] = 2 * (r.origin.x * r.direction.x + r.origin.z * r.direction.z);
	disc[2] = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	disc[3] = disc[1] * disc[1] - 4 * disc[0] * disc[2];
	if (fabs(disc[0]) < EPSILON || disc[3] < 0)
		return ;
	t[0] = cons_intersection((-disc[1] - sqrt(disc[3])) / (2 * disc[0]), s);
	t[1] = cons_intersection((-disc[1] + sqrt(disc[3])) / (2 * disc[0]), s);
}

int	cylinder_add_caps(t_shape *s, t_ray r, t_intersections *xs, int start)
{
	double	t;
	int		count;

	count = start;
	if (fabs(r.direction.y) <= EPSILON)
		return (count);
	t = (s->cylinder.minimum - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		xs->solutions[count++] = cons_intersection(t, s);
	t = (s->cylinder.maximum - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		xs->solutions[count++] = cons_intersection(t, s);
	return (count);
}
