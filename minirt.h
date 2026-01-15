/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:44 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/15 16:50:14 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINRT_H

# define EPSILON 0.00001

# include <math.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w; // 1.0 for points 0.0 for vectors
}	t_tuple;

//constructors
t_tuple	ft_vector(int x, int y, int z);
t_tuple	ft_point(int x, int y, int z);

//operations
int		op_compare(t_tuple a, t_tuple b);
t_tuple	op_add(t_tuple a, t_tuple b);
t_tuple	op_subs(t_tuple a, t_tuple b);
t_tuple	op_negate(t_tuple a);
t_tuple	op_multi(t_tuple a, double scal);
t_tuple	op_divi(t_tuple a, double scal);
double	op_magnitude(t_tuple a);
t_tuple	op_normalize(t_tuple a);
double	op_dot(t_tuple a, t_tuple b);
t_tuple	op_cross(t_tuple a, t_tuple b);

#endif