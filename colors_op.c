/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:18:42 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/15 17:39:35 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	cop_add(t_color	a, t_color b)
{
	t_color res;
	
	res.r = a.r + b.r;
	res.g = a.g + b.g;
	res.b = a.b + b.b;
	return (res);
}

t_color	cop_subs(t_color a, t_color b)
{
	t_color res;
	
	res.r = a.r - b.r;
	res.g = a.g - b.g;
	res.b = a.b - b.b;
	return (res);
}

t_color	cop_multi(t_color a, double scal)
{
	t_color res;
	
	res.r = a.r * scal;
	res.g = a.g * scal;
	res.b = a.b * scal;
	return (res);
}

t_color	cop_blend(t_color a, t_color b)
{
	t_color res;
	
	res.r = a.r * b.r;
	res.g = a.g * b.g;
	res.b = a.b * b.b;
	return (res);
}

