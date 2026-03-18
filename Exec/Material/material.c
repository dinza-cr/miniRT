/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:53:01 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 14:54:11 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_material	cons_material(void)
{
	t_material	res;

	res.color = cons_color(0, 0, 0);
	res.ambient = 0.0;
	res.diffuse = 0.0;
	res.specular = 0.0;
	res.shininess = 0.0;
	return (res);
}

t_material	init_material(void)
{
	t_material	res;

	res.color = cons_color(1, 1, 1);
	res.ambient = 0.1;
	res.diffuse = 0.9;
	res.specular = 0.9;
	res.shininess = 200.0;
	return (res);
}
