/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_matrix2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:00:23 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 15:52:47 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	mop_submatrix2(t_matrix *a, t_matrix *res, int *i)
{
	i[1] = 0;
	i[3] = 0;
	while (i[1] < a->size)
	{
		if (i[1] == i[5])
		{
			i[1]++;
			continue ;
		}
		res->m[i[2]][i[3]] = a->m[i[0]][i[1]];
		i[1]++;
		i[3]++;
	}
}

t_matrix	mop_submatrix(t_matrix a, int row, int col)
{
	t_matrix	res;
	int			i[6];

	i[4] = row;
	i[5] = col;
	res = cons_matrix(a.size - 1);
	i[0] = 0;
	i[2] = 0;
	while (i[0] < a.size)
	{
		if (i[0] == row)
		{
			i[0]++;
			continue ;
		}
		mop_submatrix2(&a, &res, i);
		i[0]++;
		i[2]++;
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
