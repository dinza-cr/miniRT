/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:18:42 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/18 19:14:05 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pixel	cop_add(t_pixel	a, t_pixel b)
{
	t_pixel	res;

	res.r = a.r + b.r;
	res.g = a.g + b.g;
	res.b = a.b + b.b;
	return (res);
}

t_pixel	cop_subs(t_pixel a, t_pixel b)
{
	t_pixel	res;

	res.r = a.r - b.r;
	res.g = a.g - b.g;
	res.b = a.b - b.b;
	return (res);
}

t_pixel	cop_multi(t_pixel a, double scal)
{
	t_pixel	res;

	res.r = a.r * scal;
	res.g = a.g * scal;
	res.b = a.b * scal;
	return (res);
}

t_pixel	cop_blend(t_pixel a, t_pixel b)
{
	t_pixel	res;

	res.r = a.r * b.r;
	res.g = a.g * b.g;
	res.b = a.b * b.b;
	return (res);
}
