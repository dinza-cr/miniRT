/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:24:08 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 19:13:33 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "../Tuples/tuple.h"

typedef struct s_sphere t_sphere;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
} t_ray;


//constructeur
t_ray	cons_ray(t_tuple origin, t_tuple direction);

t_tuple	position(t_ray r, float t);

#endif