/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_transformation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:31:45 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 18:39:01 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	trsf_translation(double x, double y, double z)
{
	t_matrix	res;

	res = cons_idmatrix();
	res.m[0][3] = x;
	res.m[1][3] = y;
	res.m[2][3] = z;
	return (res);
}

t_matrix	trsf_scaling(double x, double y, double z)
{
	t_matrix	res;

	res = cons_idmatrix();
	res.m[0][0] = x;
	res.m[1][1] = y;
	res.m[2][2] = z;
	return (res);
}

t_matrix	trsf_rotx(double radian)
{
	t_matrix	res;

	res = cons_idmatrix();
	res.m[1][1] = cos(radian);
	res.m[1][2] = -sin(radian);
	res.m[2][1] = sin(radian);
	res.m[2][2] = cos(radian);
	return (res);
}

t_matrix	trsf_roty(double radian)
{
	t_matrix	res;

	res = cons_idmatrix();
	res.m[0][0] = cos(radian);
	res.m[0][2] = sin(radian);
	res.m[2][0] = -sin(radian);
	res.m[2][2] = cos(radian);
	return (res);
}

t_matrix	trsf_rotz(double radian)
{
	t_matrix	res;

	res = cons_idmatrix();
	res.m[0][0] = cos(radian);
	res.m[0][1] = -sin(radian);
	res.m[1][0] = sin(radian);
	res.m[1][1] = cos(radian);
	return (res);
}

t_matrix	trsf_shearing(double xy, double xz, double yx, double yz, double zx, double zy)
{
	t_matrix	res;

	res = cons_idmatrix();
	res.m[0][1] = xy;
	res.m[0][2] = xz;
	res.m[1][0] = yx;
	res.m[1][2] = yz;
	res.m[2][0] = zx;
	res.m[2][1] = zy;
	return (res);
}

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
	orientation = cons_mat4(left.x, left.y, left.z, 0, true_up.x, true_up.y, true_up.z, 0, -forward.x, -forward.y, -forward.z, 0, 0, 0, 0, 1);
	return (mop_multimat(orientation,
			trsf_translation(-from.x, -from.y, -from.z)));
}
