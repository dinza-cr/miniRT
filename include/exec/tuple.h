/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:28:13 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/25 11:56:35 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w; // 1.0 for points 0.0 for vectors
}	t_tuple;

//constructeurs
t_tuple		cons_point(double x, double y, double z);
t_tuple		cons_vector(double x, double y, double z);

//tuple operations (top)
int			top_compare(t_tuple a, t_tuple b);
t_tuple		top_add(t_tuple a, t_tuple b);
t_tuple		top_subs(t_tuple a, t_tuple b);
t_tuple		top_negate(t_tuple a);
t_tuple		top_multi(t_tuple a, double scal);
t_tuple		top_divi(t_tuple a, double scal);
double		top_magnitude(t_tuple a);
t_tuple		top_normalize(t_tuple a);
double		top_dot(t_tuple a, t_tuple b);
t_tuple		top_cross(t_tuple a, t_tuple b);

#endif