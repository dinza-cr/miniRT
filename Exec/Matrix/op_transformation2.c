/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_transformation2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:26:05 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 15:38:41 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_matrix	trsf_view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		upn;
	t_tuple		true_up;
	t_matrix	orientation;

	forward = top_normalize(top_subs(to, from));
	upn = top_normalize(up);
	left = top_cross(forward, upn);
	true_up = top_cross(left, forward);
	orientation = cons_mat4(cons_tuple(left.x, left.y, left.z, 0),
			cons_tuple(true_up.x, true_up.y, true_up.z, 0),
			cons_tuple(-forward.x, -forward.y, -forward.z, 0),
			cons_tuple(0, 0, 0, 1));
	return (mop_multimat(orientation,
			trsf_translation(-from.x, -from.y, -from.z)));
}
