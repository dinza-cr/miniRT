/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:06:06 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 14:35:46 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPS_H
# define COMPS_H

# include "../Tuples/tuple.h"
# include "../Intersection/intersection.h"
# include "../Ray/ray.h"

typedef struct s_shape	t_shape;

typedef struct s_comps
{
	int			valid;
	double		t;
	t_shape		*shape;

	t_tuple		point;
	t_tuple		overpoint;
	t_tuple		eyev;
	t_tuple		normalv;

	int			inside;
}	t_comps;

//constructeur
t_comps	cons_comps(t_intersection i, t_ray r);

#endif