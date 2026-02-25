/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comps.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:06:06 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/25 11:49:21 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPS_H
# define COMPS_H

# include "../Tuples/tuple.h"
# include "../Intersection/intersection.h"
# include "../Ray/ray.h"
typedef struct s_sphere t_sphere;

typedef struct s_comps
{
    double      t;
    t_sphere    *s;

    t_tuple     point;
    t_tuple     eyev;
    t_tuple     normalv;

    int         inside;
} t_comps;

//constructeur
t_comps cons_comps(t_intersection i,t_ray r);

#endif