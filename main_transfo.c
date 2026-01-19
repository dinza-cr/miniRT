/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_transfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:43:54 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/19 17:30:47 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	t_canva *canva;
	t_pixel	white;
	t_tuple	dot;
	t_tuple	temp;
	double	radius = 40;
	int i = 0;

	dot = cons_point(0, radius, 0);
	canva = cons_canva(100, 100);
	white = cons_pixel(1,1,1);
	while (i < 12)
	{
		temp = mop_tupmulti(trsf_translation(50, 50, 0), dot);
		write_pixel(canva, temp.x, temp.y, white);
		dot = mop_tupmulti(trsf_rotz(PI/6.0), dot);
		i++;
	}
	canvas_to_ppm(canva);
}