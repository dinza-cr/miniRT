/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:59:37 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/16 18:28:17 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	mop_compare(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (fabs(a.m[i][j] - b.m[i][j]) >= EPSILON)
				return (0);
			j++;
		}
		j++;
	}
	return (1);
}

t_matrix mop_matmulti(t_matrix a, t_matrix b)
{
	t_matrix	res;
	int			i;
	int			j;

	i = 0;
	res = cons_matrix(4);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.m[i][j] = (a.m[i][0] * b.m[0][j])
						+ (a.m[i][1] * b.m[1][j])
						+ (a.m[i][2] * b.m[2][j])
						+ (a.m[i][3] * b.m[3][j]);
			j++;
		}
		i++;
	}
	return (res);
}

t_tuple	mop_tupmulti(t_matrix a, t_tuple b)
{
	t_tuple	res;

	res.x = a.m[0][0] * b.x
			+ a.m[0][1] * b.y
			+ a.m[0][2] * b.z
			+ a.m[0][3] * b.w;
	res.y = a.m[1][0] * b.x
			+ a.m[1][1] * b.y
			+ a.m[1][2] * b.z
			+ a.m[1][3] * b.w;
	res.z = a.m[2][0] * b.x
			+ a.m[2][1] * b.y
			+ a.m[2][2] * b.z
			+ a.m[2][3] * b.w;
	res.w = a.m[3][0] * b.x
			+ a.m[3][1] * b.y
			+ a.m[3][2] * b.z
			+ a.m[3][3] * b.w;
	return (res);
}