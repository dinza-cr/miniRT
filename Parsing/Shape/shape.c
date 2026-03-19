/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:01:56 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/19 14:19:31 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_shape	*cons_shape(void)
{
	t_shape	*res;

	res = malloc(sizeof(t_shape));
	if (!res)
		return (NULL);
	res->transformation = cons_idmatrix();
	res->inv_transfo = cons_idmatrix();
	res->material = init_material();
	res->next = NULL;
	res->sphere = cons_sphere();
	res->plane = cons_plane();
	res->cylinder = cons_cylinder();
	return (res);
}

void dest_shape(t_shape *shape)
{
	t_shape	*temp;

	if (!shape)
		return ;
	temp = shape;
	while (temp)
	{
		temp = temp->next;
		free(shape);
		shape = temp;
	}
	free(shape);
}

void	set_transform(t_shape *s, t_matrix t)
{
	s->transformation = t;
	s->inv_transfo = mop_inverse(t);
}
