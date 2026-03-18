/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:57:06 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 14:56:49 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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

t_matrix	cons_mat4(t_tuple a, t_tuple b, t_tuple c, t_tuple d)
{
	t_matrix	res;

	res = cons_matrix(4);
	res.m[0][0] = a.x;
	res.m[0][1] = a.y;
	res.m[0][2] = a.z;
	res.m[0][3] = a.w;
	res.m[1][0] = b.x;
	res.m[1][1] = b.y;
	res.m[1][2] = b.z;
	res.m[1][3] = b.w;
	res.m[2][0] = c.x;
	res.m[2][1] = c.y;
	res.m[2][2] = c.z;
	res.m[2][3] = c.w;
	res.m[3][0] = d.x;
	res.m[3][1] = d.y;
	res.m[3][2] = d.z;
	res.m[3][3] = d.w;
	return (res);
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
