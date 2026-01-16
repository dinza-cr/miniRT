/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:02:56 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/16 15:38:51 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main()
{
	t_canva *canva;
	t_color color;

	canva = cons_canva(4, 4);
	color = cons_color(1, 0, 0);
	write_pixel(canva, 3, 3, color);
	write_pixel(canva, 2, 3, color);
	write_pixel(canva, 1, 3, color);
	write_pixel(canva, 0, 3, color);
	canvas_to_ppm(canva);
	return (0);
}