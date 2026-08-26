/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:24:08 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/25 11:47:18 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "exec/tuple.h"
# include "exec/matrix.h"

typedef struct s_sphere	t_sphere;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

//constructeur
t_ray	cons_ray(t_tuple origin, t_tuple direction);

//ray operations (rop)
t_tuple	rop_position(t_ray r, float t);
t_ray	rop_transform(t_ray ray, t_matrix matrix);

#endif