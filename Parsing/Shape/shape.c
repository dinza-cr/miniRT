/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:01:56 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/06 15:09:59 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_shape *cons_shape(void)
{
    t_shape *res;

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