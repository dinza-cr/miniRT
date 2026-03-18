/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_matrix3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:01:41 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 15:02:29 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double	mop_cofactor4(t_matrix a, int row, int col)
{
	double	minor;
	double	res;

	minor = mop_minor4(a, row, col);
	if ((row + col) % 2 == 0)
		res = minor;
	else
		res = 0 - minor;
	return (res);
}

double	mop_det4(t_matrix a)
{
	double	res;
	int		j;

	j = 0;
	res = 0;
	while (j < 4)
	{
		res = res + a.m[0][j] * mop_cofactor4(a, 0, j);
		j++;
	}
	return (res);
}

int	mop_isinvertible(t_matrix a)
{
	double	det;

	det = 0.0;
	if (a.size == 2)
		det = mop_det2(a);
	else if (a.size == 3)
		det = mop_det3(a);
	else if (a.size == 4)
		det = mop_det4(a);
	if (fabs(det) >= EPSILON)
		return (1);
	else
		return (0);
}

double	mop_det(t_matrix a)
{
	if (a.size == 2)
		return (mop_det2(a));
	else if (a.size == 3)
		return (mop_det3(a));
	else if (a.size == 4)
		return (mop_det4(a));
	else
		return (1);
}

double	mop_cofactor(t_matrix a, int row, int col)
{
	if (a.size == 3)
		return (mop_cofactor3(a, row, col));
	else if (a.size == 4)
		return (mop_cofactor4(a, row, col));
	return (0);
}
