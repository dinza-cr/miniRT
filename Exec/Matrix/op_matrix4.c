/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_matrix4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:02:34 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/24 18:13:21 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_matrix	mop_comat(t_matrix a)
{
	t_matrix	res;
	int			i;
	int			j;

	res = cons_matrix(a.size);
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			res.m[i][j] = mop_cofactor(a, i, j);
			j++;
		}
		i++;
	}
	return (res);
}

t_matrix	mop_inverse(t_matrix a)
{
	t_matrix	res;
	double		det;
	int			i;
	int			j;

	det = mop_det(a);
	if (!isfinite(det) || fabs(det) <= EPSILON)
		return (cons_idmatrix());
	res = mop_comat(a);
	res = mop_transpose(res);
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			res.m[i][j] = res.m[i][j] / det;
			if (!isfinite(res.m[i][j]))
				return (cons_idmatrix());
			j++;
		}
		i++;
	}
	return (res);
}

t_matrix	mop_copy(t_matrix a)
{
	t_matrix	res;
	int			i;
	int			j;

	i = 0;
	j = 0;
	res = cons_matrix(a.size);
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			res.m[i][j] = a.m[i][j];
			j++;
		}
		i++;
	}
	return (res);
}

double	mop_minor4(t_matrix a, int row, int col)
{
	double	res;

	res = mop_det3(mop_submatrix(a, row, col));
	return (res);
}
