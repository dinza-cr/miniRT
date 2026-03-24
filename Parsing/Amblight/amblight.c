/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amblight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:17:36 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 16:43:40 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_amblight	pars_amblight(char **info, t_world *world)
{
	t_amblight	res;

	res.valid = 0;
	world->has_ambient = 1;
	if (count_elem(info) != 3)
		return (res);
	res.ratio = ft_atod(info[1]);
	if (!in_finite_range(res.ratio, 0.0, 1.0))
		return (res);
	res.color = get_color(info[2]);
	if (res.color.r == -1)
		return (res);
	res.valid = 1;
	return (res);
}
