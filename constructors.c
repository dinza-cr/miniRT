/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:50:21 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/15 16:50:22 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_point(int x, int y, int z)
{
	t_tuple	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = 1.0;
	return (res);
}

t_tuple	ft_vector(int x, int y, int z)
{
	t_tuple	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = 0.0;
	return (res);
}