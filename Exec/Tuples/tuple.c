/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:30:18 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 14:59:40 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//constructors
t_tuple	cons_point(double x, double y, double z)
{
	t_tuple	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = 1.0;
	return (res);
}

t_tuple	cons_vector(double x, double y, double z)
{
	t_tuple	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = 0.0;
	return (res);
}

t_tuple	cons_tuple(double x, double y, double z, double w)
{
	t_tuple	res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.w = w;
	return (res);
}