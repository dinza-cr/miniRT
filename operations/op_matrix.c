/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:59:37 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/27 17:29:58 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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
		i++;
	}
	return (1);
}

t_matrix	mop_multimat(t_matrix a, t_matrix b)
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

t_tuple	mop_multitup(t_matrix a, t_tuple b)
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

t_matrix	mop_transpose(t_matrix a)
{
	t_matrix	res;
	int			i;
	int			j;

	i = 0;
	res = cons_matrix(a.size);
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			res.m[i][j] = a.m[j][i];
			j++;
		}
		i++;
	}
	return (res);
}

double	mop_det2(t_matrix a)
{
	double	res;

	res = a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0];
	return (res);
}

t_matrix	mop_submatrix(t_matrix a, int row, int col)
{
	t_matrix	res;
	int			i;
	int			j;
	int			k;
	int			l;

	res = cons_matrix(a.size - 1);
	i = 0;
	k = 0;
	while (i < a.size)
	{
		if (i == row)
		{
			i++;
			continue ;
		}
		j = 0;
		l = 0;
		while (j < a.size)
		{
			if (j == col)
			{
				j++;
				continue ;
			}
			res.m[k][l] = a.m[i][j];
			j++;
			l++;
		}
		i++;
		k++;
	}
	return (res);
}

double	mop_minor3(t_matrix a, int row, int col)
{
	t_matrix	submat;
	double		res;

	submat = mop_submatrix(a, row, col);
	res = mop_det2(submat);
	return (res);
}

double	mop_cofactor3(t_matrix a, int row, int col)
{
	double	minor;
	double	res;

	minor = mop_minor3(a, row, col);
	if ((row + col) % 2 == 0)
		res = minor;
	else
		res = 0 - minor;
	return (res);
}

double	mop_det3(t_matrix a)
{
	double	res;
	int		j;

	j = 0;
	res = 0;
	while (j < 3)
	{
		res = res + a.m[0][j] * mop_cofactor3(a, 0, j);
		j++;
	}
	return (res);
}

double	mop_minor4(t_matrix a, int row, int col)
{
	double	res;

	res = mop_det3(mop_submatrix(a, row, col));
	return (res);
}

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

t_matrix	mop_comat(t_matrix a)
{
	t_matrix	res;
	int	i;
	int	j;

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
	if (fabs(det) <= EPSILON)
		return (cons_matrix(0));
	res = mop_comat(a);
	res = mop_transpose(res);
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			res.m[i][j] = res.m[i][j] / det;
			j++;
		}
		i++;
	}
	return (res);
}
