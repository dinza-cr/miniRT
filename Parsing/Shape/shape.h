/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:01:10 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 15:05:28 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "../../Exec/Matrix/matrix.h"
# include "../../Exec/Material/material.h"
# include "../Sphere/sphere.h"
# include "../Plane/plane.h"
# include "../Cylinder/cylinder.h" 


typedef struct s_shape
{
    t_matrix    transformation;
    t_matrix    inv_transfo;
    t_material  material;

    t_sphere    sphere;
    t_plane     plane;
    t_cylinder  cylinder;

    t_shape     *next;
}   t_shape;

t_shape *cons_shape(void);

#endif