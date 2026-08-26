/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:57:06 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 17:13:06 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	cons_matrix(int size)
{
	t_matrix	res;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res.m[i][j] = 0.0;
			j++;
		}
		i++;
	}
	if (size < 2 || size > 4)
	{
		res.size = 0;
		printf("wrong matrix size !!! \n");
		return (res);
	}
	res.size = size;
	return (res);
}

t_matrix	cons_mat4(double a0, double a1, double a2, double a3, double b0, double b1, double b2, double b3, double c0, double c1, double c2, double c3, double d0, double d1, double d2, double d3)
{
	t_matrix A;

	A = cons_matrix(4);
	
	A.m[0][0] = a0;
	A.m[0][1] = a1;
	A.m[0][2] = a2;
	A.m[0][3] = a3;

	A.m[1][0] = b0;
	A.m[1][1] = b1;
	A.m[1][2] = b2;
	A.m[1][3] = b3;

	A.m[2][0] = c0;
	A.m[2][1] = c1;
	A.m[2][2] = c2;
	A.m[2][3] = c3;

	A.m[3][0] = d0;
	A.m[3][1] = d1;
	A.m[3][2] = d2;
	A.m[3][3] = d3;

	return (A);
}

t_matrix	cons_idmatrix(void)
{
	t_matrix	res;

	res = cons_matrix(4);
	res.m[0][0] = 1.0;
	res.m[1][1] = 1.0;
	res.m[2][2] = 1.0;
	res.m[3][3] = 1.0;
	return (res);
}
