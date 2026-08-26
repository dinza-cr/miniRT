/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:01:10 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/11 14:55:54 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "exec/matrix.h"
# include "exec/material.h"
# include "parsing/sphere.h"
# include "parsing/plane.h"
# include "parsing/cylinder.h" 

typedef struct s_shape
{
	t_matrix		transformation;
	t_matrix		inv_transfo;
	t_material		material;
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
	struct s_shape	*next;
}	t_shape;

t_shape	*cons_shape(void);

void	set_transform(t_shape *s, t_matrix t);

#endif